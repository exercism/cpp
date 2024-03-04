#!/usr/bin/env bash
set -e

print_help() {
    echo "This script verifies if one or more files are formatted using the provided"
    echo ".clang-format configuration, it does so by diffing the current content of"
    echo "a file and the result of calling clang-format with that file, if there's"
    echo "no difference the file is formatted correctly."
    echo "This script does NOT edit any existing file."
    echo
    echo "Usage:"
    echo "    ./check-formatting.sh [-h|--help] path_to_file..."
    echo "     path_to_file must be one or more paths to existing regular files,"
    echo "     warnings are returned for each invalid path."
}

# Get files list
FILES=()
while [[ $# -gt 0 ]]
do
    key="$1"
    case $key in
        -h|--help)
        print_help
        exit 0
        ;;
        *)
        FILES+=("$key")
    esac
    shift
done

# Result of this script
RESULT=0

# Iterate files to run format check
for INDEX in "${!FILES[@]}"; do
    FILE="${FILES[$INDEX]}"
    if [[ -f "$FILE" ]]; then
        if ! clang-format --dry-run --Werror "$FILE"; then
            RESULT=1
        fi
    elif [[ -d "$FILE" ]]; then
        echo "Path is a directory: $FILE"
        RESULT=1
    else
        echo "File not found: $FILE"
        RESULT=1
    fi
done

echo "Done"
exit $RESULT
