cmake_minimum_required(VERSION 3.28)
project(precursor C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
if (
(${CMAKE_C_COMPILER_ID} STREQUAL "Clang") OR
(${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
)
    set(CMAKE_C_FLAGS "--pedantic -Werror -Wall -Wextra")
endif ()
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

add_library(precursor SHARED
        precursor/colour.h
        precursor/terminal.h
        precursor/colour.c
        precursor/ansi_terminal.c
        precursor/ansi_terminal.h
)
target_include_directories(precursor PUBLIC precursor)

add_executable(precursor_demo demos/demo.c)
target_link_libraries(precursor_demo precursor)

