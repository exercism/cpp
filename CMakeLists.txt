cmake_minimum_required(VERSION 3.1.3)
project(exercism CXX)

set(alt_exercise_tree ${CMAKE_CURRENT_SOURCE_DIR}/build_exercises)

function(travis_fixup exercise_dir alt_exercise_root)
    string(REPLACE "-" "_" file ${exercise_dir})
    set(source ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${exercise_dir})
    if(EXISTS ${source})
        set(alt_exercise_dir ${alt_exercise_root}/${exercise_dir})
        file(COPY ${source} DESTINATION ${alt_exercise_root})
        if(EXISTS ${alt_exercise_dir}/example.h)
            file(RENAME ${alt_exercise_dir}/example.h ${alt_exercise_dir}/${file}.h)
        endif()
        if(EXISTS ${alt_exercise_dir}/example.cpp)
            file(RENAME ${alt_exercise_dir}/example.cpp ${alt_exercise_dir}/${file}.cpp)
        endif()
    endif()
endfunction()

option(EXERCISM_RUN_ALL_TESTS "Run all Exercism tests" On)

foreach(exercise
    hello-world
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
    pascals-triangle
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
    all-your-base
    pangram
    binary-search
    isogram
    reverse-string
    acronym
)
    travis_fixup(${exercise} ${alt_exercise_tree})
    add_subdirectory(${alt_exercise_tree}/${exercise})
endforeach()
