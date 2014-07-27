project (Hamming)

include_directories(${PROJECT_SOURCE_DIR}/../include)
include_directories(${PROJECT_SOURCE_DIR}/../include/Hamming/)

add_library(Hamming ./Hamming/Hamming.cpp)
