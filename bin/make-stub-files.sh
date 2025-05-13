#!/usr/bin/env bash
#
# Helper script to fix up incorrect namespaces and add stub files.

exercises_dir=$(cd "$(dirname "$0")/../exercises" && pwd)

for exercise_dir in "${exercises_dir}"/*; do
    cd "$exercise_dir" || exit 1
    exercise_name=$(basename "$(pwd)" | sed 's/-/_/g')
    # Rename incorrect namespaces
    if ! grep -q "namespace $exercise_name" ./*.cpp ./*.h; then
        echo "Cleaning up $exercise_name"
        old=$(grep '^namespace [[:lower:]_]*' *.h --no-filename --max-count 1 --only-matching | head -1 | cut -d ' ' -f2)
        find . -name "*.h" -exec sed -i "s/namespace $old/namespace $exercise_name/g" {} \;
        find . -name "*.cpp" -exec sed -i "s/namespace $old/namespace $exercise_name/g" {} \;
        find . -name "*.h" -exec sed -i "s/$old::/$exercise_name::/g" {} \;
        find . -name "*.cpp" -exec sed -i "s/$old::/$exercise_name::/g" {} \;
        git commit * -m "$exercise_name: Fix-up namespace"
    fi
    # Add stubs if they don't exist
    header="$exercise_name.h"
    source="$exercise_name.cpp"
    if ! test -f "$header"; then
        printf "#pragma once\n" >> $header
        printf "\nnamespace $exercise_name {\n\n}  // namespace $exercise_name\n" >> $header
        git add $header
    fi
    if ! test -f "$source"; then
        printf "#include \"$header\"\n" >> $source
        printf "\nnamespace $exercise_name {\n\n}  // namespace $exercise_name\n" >> $source
        git add $source
    fi
done
