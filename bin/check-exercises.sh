#!/usr/bin/env bash
#
# Runs tests only if the current Pull Request has modified a test or the root
# CMakeLists.txt, or if we are running on the master branch.

# Fail if any command fails
set -e

repo=$(cd "$(dirname "$0")/.." && pwd)

# Configure all the tests.
if [ "$EXERCISM_COMMON_CATCH" == "false" ]; then
    echo "Using bundled Catch main libraries."
    cmake -G Ninja -DEXERCISM_COMMON_CATCH=OFF "$repo"
else
    echo "Using a common Catch main library."
    cmake -G Ninja "$repo"
fi
echo ""

# Compiling just hello world directly from its directory. This matches the
# flow of students directly.
hello_world_dir="$repo"/build_exercises/hello-world
cmake -G Ninja "$hello_world_dir"
cmake --build "$hello_world_dir"

if [ "$TRAVIS_PULL_REQUEST" == "false" ]; then
    echo "This is not a Pull Request, running all tests."
    cmake --build "$repo"
elif git diff --name-only master | grep "^CMakeLists.txt"; then
    echo "This PR changes the root CMakeLists.txt."
    echo "Running a single test and then all tests."
    cmake --build "$repo" -- test_hello-world
    cmake --build "$repo"
else
    tests="$(git diff --name-only master | grep "^exercises/" | cut -d '/' -f2 | sed 's/.*/test_&/' | uniq | tr '\n' ' ')"
    if [ ${#tests} -ne 0 ]; then
        echo "Running only tests that have changed."
        cmake --build "$repo" -- $tests
    else
        echo "No tests changed."
    fi
fi
