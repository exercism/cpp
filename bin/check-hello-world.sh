#!/usr/bin/env bash
#
# Test that the hello-world exercise compiles with no changes and fails.

# Fail if any command fails
set -e

repo=$(cd "$(dirname "$0")/.." && pwd)

hello_world_tmp_dir="$repo"/build_hello-world
hello_world_dir="$repo"/exercises/hello-world

mkdir -p "$hello_world_tmp_dir"

cd "$hello_world_tmp_dir"

# Configuring should work.
cmake "$hello_world_dir"

echo "Building hello-world, which should fail."

# The build will fail, since it runs a failing test.
if cmake --build .; then
    # The build succeeded, which is not supposed to happen.
    exit 1
fi

cd "$repo"
