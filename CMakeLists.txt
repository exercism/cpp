cmake_minimum_required(VERSION 3.5.1)
project(exercism CXX)

set(alt_exercise_tree ${CMAKE_CURRENT_SOURCE_DIR}/build_exercises/practice)

function(build_fixup exercise_dir alt_exercise_root)
    string(REPLACE "-" "_" file ${exercise_dir})
    set(source ${CMAKE_CURRENT_SOURCE_DIR}/exercises/practice/${exercise_dir})
    if(EXISTS ${source})
        set(alt_exercise_dir ${alt_exercise_root}/${exercise_dir})
        file(COPY ${source} DESTINATION ${alt_exercise_root})
        if(EXISTS ${alt_exercise_dir}/.meta/example.h)
            file(RENAME ${alt_exercise_dir}/.meta/example.h ${alt_exercise_dir}/${file}.h)
        endif()
        if(EXISTS ${alt_exercise_dir}/.meta/example.cpp)
            file(RENAME ${alt_exercise_dir}/.meta/example.cpp ${alt_exercise_dir}/${file}.cpp)
        endif()
    endif()
endfunction()

option(EXERCISM_RUN_ALL_TESTS "Run all Exercism tests" On)
option(EXERCISM_COMMON_CATCH "Link against a common Catch2 main lib." On)

if(EXERCISM_COMMON_CATCH)
    add_library(catchlib OBJECT test/tests-main.cpp)
    set_target_properties(catchlib PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED OFF
        CXX_EXTENSIONS OFF
    )
endif()

file(GLOB exercise_list ${CMAKE_CURRENT_SOURCE_DIR}/exercises/practice/*)

foreach(exercise_dir ${exercise_list})
    get_filename_component(exercise ${exercise_dir} NAME)
    build_fixup(${exercise} ${alt_exercise_tree})
    add_subdirectory(${alt_exercise_tree}/${exercise})
endforeach()
