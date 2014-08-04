cmake_minimum_required(VERSION 2.8)
project(exercism CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time)
message("Boost includes:  " ${Boost_INCLUDE_DIRS})
message("Boost libraries: " ${Boost_LIBRARIES})

function(exercism exe)
    string(REPLACE "-" "_" file ${exe})
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
