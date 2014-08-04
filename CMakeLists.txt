cmake_minimum_required(VERSION 2.8.11)
project(exercism CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time)

function(exercism exe)
    string(REPLACE "-" "_" file ${exe})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example.h)
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/example.h ${CMAKE_CURRENT_SOURCE_DIR}/${file}.h)
    endif()
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp)
        file(COPY EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    endif()
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
        set(exercise_cpp ${file}.cpp)
    else()
        set(exercise_cpp "")
    endif()
    add_executable(${exe} ${exercise_test_cpp} ${exercise_cpp} ${exercise_h})
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
    point-mutations
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
