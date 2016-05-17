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
find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework  regex)

# Configure to run all the tests?
if(${EXERCISM_RUN_ALL_TESTS})
    add_definitions(-DEXERCISM_RUN_ALL_TESTS)
endif()

FILE(GLOB sources *.cpp)

# Build executable from sources (including headers is bad practice)
add_executable( ${exercise} ${sources} )

#Use a recent-ish standard
target_compile_features( ${exercise} PRIVATE cxx_override )

# We need boost includes
target_include_directories(${exercise} PRIVATE ${Boost_INCLUDE_DIRS})

# We need boost libraries
target_link_libraries(${exercise} ${Boost_LIBRARIES})

# Tell MSVC not to warn us about unchecked iterators in debug builds
if(${MSVC})
    set_target_properties(${exercise} PROPERTIES
        COMPILE_DEFINITIONS_DEBUG _SCL_SECURE_NO_WARNINGS)
endif()

# Run the tests on every build
add_custom_command(TARGET ${exercise} POST_BUILD COMMAND ${exercise} --detect_memory_leak=1 --log_level=message --random=1 )
