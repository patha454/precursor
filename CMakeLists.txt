cmake_minimum_required(VERSION 3.28)
project(src C)
include(CTest)

set(UNIT_TESTING OFF BOOL "Build unit tests")
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

add_library(precursor SHARED
        src/colour.h
        src/terminal.h
        src/colour.c
        src/ansi_terminal.c
        src/ansi_terminal.h
)
target_include_directories(precursor PUBLIC src)

add_executable(precursor_demo demos/demo.c)
target_link_libraries(precursor_demo precursor)

if (
(${CMAKE_C_COMPILER_ID} STREQUAL "Clang") OR
(${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
)
    target_compile_options(precursor PRIVATE "--pedantic" "-Werror" "-Wall" "-Wextra")
    target_compile_options(precursor_demo PRIVATE "--pedantic" "-Werror" "-Wall" "-Wextra")
endif ()

if (UNIT_TESTING)
    include(FetchCMocka.cmake)
    add_executable(precursor_unit_tests src/precursor_tests.c)
    target_link_libraries(precursor_unit_tests PRIVATE cmocka-static)
    target_include_directories(precursor_unit_tests PRIVATE ${cmocka-header_SOURCE_DIR})
endif()
