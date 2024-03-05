#! /usr/bin/env python3

"""Translate the language-independent tests to C++ code."""

import argparse
import json
import re
import sys
import textwrap
import tomllib


def main():
    """Read tests.toml and canonical-data.json and print C++ tests."""
    args = parse_arguments()
    with open(args.toml, 'rb') as file:
        toml_data = tomllib.load(file)
    with open(args.canonical_data) as file:
        json_data = json.load(file)

    slug_snake = json_data['exercise'].replace('-', '_')
    print_head(slug_snake)

    testcases = collect_testcases(toml_data, json_data)
    for i, case in enumerate(testcases):
        if i == 1:
            print('#if defined(EXERCISM_RUN_ALL_TESTS)')
            print()
        print_case(slug_snake, case)

    if len(testcases) > 1:
        print('#endif  // EXERCISM_RUN_ALL_TESTS')


def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        'toml',
        help='TOML file with the selected tests')
    parser.add_argument(
        'canonical_data',
        help='JSON file with the canonical tests')
    return parser.parse_args()


def collect_testcases(toml_data, json_data):
    """Build a list of testcases, according to tests.toml."""
    included_uuids = {
            uuid for uuid, kv_pairs in toml_data.items()
            if kv_pairs.get('include', True)}
    return [
            case for case in json_data['cases']
            if case['uuid'] in included_uuids]


def print_head(slug_snake):
    """Print the head of the test file."""
    print(textwrap.dedent(f'''\
        #include "{slug_snake}.h"
        #include <vector>
        #ifdef EXERCISM_TEST_SUITE
        #include <catch2/catch.hpp>
        #else
        #include "test/catch.hpp"
        #endif
    '''))


def print_case(slug_snake, case):
    """Print a single test case."""
    test_name = case['description']
    uuid = case['uuid']
    prop = case['property']
    prop_snake = to_snake_case(prop)

    max_weight = case['input']['maximumWeight']
    items = case['input']['items']
    expected = case['expected']

    items = [
            f'{{{item["weight"]}, {item["value"]}}}'
            for item in case['input']['items']]

    # all items on one line would make that line too long
    if len(items) <= 3:
        items = ', '.join(items)
    else:
        indent = "\n" + " " * 20
        items = ','.join(
                f'{" " if i % 5 else indent}{item}'
                for i, item in enumerate(items))

    print(textwrap.dedent(f'''\
        TEST_CASE("{test_name}", "[{prop}][{uuid}]")
        {{
            int max_weight = {max_weight};
            const std::vector<knapsack::Item> items{{{items}}};
            REQUIRE({slug_snake}::{prop_snake}(max_weight, items) == {expected});
        }}
        '''))


def to_snake_case(str_):
    str_ = re.sub(
            '([a-z])([A-Z])',
            lambda match: f'{match.group(1)}_{match.group(2).lower()}',
            str_)
    str_ = str_.replace('-', '_')
    return str_


if __name__ == '__main__':
    main()
