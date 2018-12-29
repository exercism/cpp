cmake_minimum_required(VERSION 3.1.3)
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
    pangram
    reverse-string
)
    travis_fixup(${exercise})
    add_subdirectory(exercises/${exercise})
endforeach()
