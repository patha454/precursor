cmake_minimum_required(VERSION 3.28)
project(precursor C)

set(CMAKE_C_STANDARD 23)

add_library(precursor SHARED
        demo.c
        colour.h
        terminal.h
        terminal.c
        colour.c
)

add_executable(precursor_demo demo.c)
target_link_libraries(precursor_demo precursor)

