cmake_minimum_required(VERSION 3.1.3)
project(exercism CXX)

set(alt_exercise_tree ${CMAKE_CURRENT_SOURCE_DIR}/build_exercises)

function(travis_fixup dir)
    string(REPLACE "-" "_" file ${dir})
    set(source ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${dir})
    if(EXISTS ${source})
        set(exercise_dir ${alt_exercise_tree}/${dir})
        file(COPY ${source} DESTINATION ${alt_exercise_tree})
        if(EXISTS ${exercise_dir}/example.h)
            file(RENAME ${exercise_dir}/example.h ${exercise_dir}/${file}.h)
        endif()
        if(EXISTS ${exercise_dir}/example.cpp)
            file(RENAME ${exercise_dir}/example.cpp ${exercise_dir}/${file}.cpp)
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
    reverse-string
    acronym
)
    travis_fixup(${exercise})
    add_subdirectory(${alt_exercise_tree}/${exercise})
endforeach()
