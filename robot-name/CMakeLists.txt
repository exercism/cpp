# Get the exercise name from the current directory
get_filename_component(exercise ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# Basic CMake project
cmake_minimum_required(VERSION 2.8.11)
# Name the project after the exercise
project(${exercise} CXX)

# Locate Boost libraries: unit_test_framework, date_time and regex
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time regex)

# gcc/clang won't enable C++11 features without this flag
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

# Configure to run all the tests?
if(${EXERCISM_RUN_ALL_TESTS})
    add_definitions(-DEXERCISM_RUN_ALL_TESTS)
endif()

# Make an executable that runs the exercism unit tests against the implementation
function(exercism)
    # Replace -'s with _'s to get a filename from the exercise name
    string(REPLACE "-" "_" file ${exercise})
    # Implementation could be only a header
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
        set(exercise_cpp ${file}.cpp)
    else()
        set(exercise_cpp "")
    endif()
    # Build executable from sources and headers
    add_executable(${exercise} ${file}_test.cpp ${exercise_cpp} ${file}.h)
    # We need boost includes
    target_include_directories(${exercise} PRIVATE ${Boost_INCLUDE_DIRS})
    # We need boost libraries
    target_link_libraries(${exercise} ${Boost_LIBRARIES})
    # Run the tests on every build
    add_custom_command(TARGET ${exercise} POST_BUILD COMMAND ${exercise})
endfunction()

exercism()
