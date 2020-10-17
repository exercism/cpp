#!/usr/bin/env bash

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

cd "$(dirname "$0")"

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

# Verifies a single file is formatted following .clang-format style
run_check() {
    local FILE="$1"
    CHECK_RESULT=0
    # Get diff between current content and formatted content
    local OUTPUT=$(diff -u <(cat "$FILE") <(clang-format --style=file "$FILE"))
    # Shows diff output only if files are different
    if [[ $OUTPUT != "" ]]; then
        echo "$OUTPUT"
        CHECK_RESULT=1
    fi
}

# Result of this script, incremented by one for each unformatted file
RESULT=0
# List of warnings
WARNINGS=()

# Iterate files to run format check
for INDEX in "${!FILES[@]}"; do
    FILE="${FILES[$INDEX]}"
    if [[ -f "$FILE" ]]; then
        run_check $FILE
        RESULT=$(( RESULT + CHECK_RESULT ))
    elif [[ -d "$FILE" ]]; then
        WARNINGS+=("Path is a directory: $FILE")
    else
        WARNINGS+=("File not found: $FILE")
    fi
done

for INDEX in "${!WARNINGS[@]}"; do
    echo "${WARNINGS[$INDEX]}"
done

echo "Done"
exit $RESULT
