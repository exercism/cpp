#!/usr/bin/env bash

# This ensures that the track configuration files are formatted correctly.

repo=$(cd "$(dirname "$0")/.." && pwd)
configlet="${repo}/bin/configlet"

if ! cfg=$($configlet fmt .); then
    echo "configlet fmt returned non-0 exit code with output:"
    echo "$cfg"
    exit 1
fi

if git diff-index --quiet HEAD --; then
    # No changes detected
    echo "configlet fmt: no changes needed"
    exit 0
else
    # Changes needed
    echo "configlet fmt: changes needed"
    echo "Run 'bin/fetch-configlet && bin/configlet fmt .' to apply these changes."
    echo ""
    git diff
    exit 1
fi

exit 0
