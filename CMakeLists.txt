cmake_minimum_required(VERSION 2.8.11)
project(exercism CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time regex)

if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

add_definitions(-DEXERCISM_RUN_ALL_TESTS)

function(travis_fixup file)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example.h)
        file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/example.h ${CMAKE_CURRENT_SOURCE_DIR}/${file}.h)
    endif()
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp)
        file(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    endif()
endfunction()

function(exercism exe)
    string(REPLACE "-" "_" file ${exe})
    travis_fixup(${file})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
        set(exercise_cpp ${file}.cpp)
    else()
        set(exercise_cpp "")
    endif()
    add_executable(${exe} ${file}_test.cpp ${exercise_cpp} ${file}.h)
    target_include_directories(${exe} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${exe} ${Boost_LIBRARIES})
    add_custom_command(TARGET ${exe} POST_BUILD COMMAND ${exe})
endfunction()

foreach(exercise
    bob
    word-count
    hamming
    anagram
    food-chain
    beer-song
    nucleotide-count
    rna-transcription
    phone-number
    grade-school
    robot-name
    leap
    etl
    space-age
    grains
    gigasecond
    triangle
    clock
)
    add_subdirectory(${exercise})
endforeach()
