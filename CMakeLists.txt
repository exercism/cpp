cmake_minimum_required(VERSION 2.8.11)
project(exercism CXX)

function(travis_fixup dir)
    string(REPLACE "-" "_" file ${dir})
    set(subdir ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${dir})
    if(EXISTS ${subdir}/example.h)
        file(RENAME ${subdir}/example.h ${subdir}/${file}.h)
    endif()
    if(EXISTS ${subdir}/example.cpp)
        file(RENAME ${subdir}/example.cpp ${subdir}/${file}.cpp)
    endif()
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
    raindrops
    difference-of-squares
    roman-numerals
    nth-prime
    sieve
    binary
    sum-of-multiples
    series
    prime-factors
    trinary
    crypto-square
    scrabble-score
    hexadecimal
    say
    meetup
    queen-attack
    allergies
    atbash-cipher
    bracket-push
)
    set(exercise_dir exercises/${exercise})
    travis_fixup(${exercise})
    execute_process(
        COMMAND ${CMAKE_COMMAND} -DEXERCISM_RUN_ALL_TESTS:BOOL=1 -G ${CMAKE_GENERATOR} .
        WORKING_DIRECTORY ${exercise_dir})
    add_custom_target(${exercise} ALL
        COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${exercise_dir})
endforeach()
