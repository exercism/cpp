cmake_minimum_required(VERSION 3.5.1)
project(exercism CXX)

function(build_fixup exercise_dir alt_exercise_root exercise_type example_name)
    string(REPLACE "-" "_" file ${exercise_dir})
    set(source ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${exercise_type}/${exercise_dir})
    if(EXISTS ${source})
        set(alt_exercise_dir ${alt_exercise_root}/${exercise_dir})
        file(COPY ${source} DESTINATION ${alt_exercise_root})
        if(EXISTS ${alt_exercise_dir}/.meta/${example_name}.h)
            file(RENAME ${alt_exercise_dir}/.meta/${example_name}.h ${alt_exercise_dir}/${file}.h)
        endif()
        if(EXISTS ${alt_exercise_dir}/.meta/${example_name}.cpp)
            file(RENAME ${alt_exercise_dir}/.meta/${example_name}.cpp ${alt_exercise_dir}/${file}.cpp)
        endif()
    endif()
endfunction()

function(iterate_exercises exercise_type example_name)
    file(GLOB exercise_list ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${exercise_type}/*)
    set(alt_exercise_tree ${CMAKE_CURRENT_SOURCE_DIR}/build_exercises/${exercise_type})
    foreach(exercise_dir ${exercise_list})
        get_filename_component(exercise ${exercise_dir} NAME)
        build_fixup(${exercise} ${alt_exercise_tree} ${exercise_type} ${example_name})
        add_subdirectory(${alt_exercise_tree}/${exercise})
    endforeach()
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

iterate_exercises("practice" "example")
