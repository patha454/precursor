cmake_minimum_required(VERSION 3.28)
project(precursor C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
ENDIF ()

add_library(precursor SHARED
        demo.c
        colour.h
        terminal.h
        colour.c
        ansi_terminal.c
        ansi_terminal.h
)

add_executable(precursor_demo demo.c)
target_link_libraries(precursor_demo precursor)

