cmake_minimum_required(VERSION 3.28)
set(PRECURSOR_PROJECT_NAME "precursor")
set(PRECURSOR_LIBRARY_NAME "${PRECURSOR_PROJECT_NAME}")
set(PRECURSOR_MAJOR_VERSION "0" CACHE STRING "Major version of this Precursor build")
set(PRECURSOR_MINOR_VERSION "0" CACHE STRING "Minor version of this Precursor build")
set(PRECURSOR_PATCH_VERSION "0" CACHE STRING "Patch version of this Precursor build")
set(PRECURSOR_VERSION "${PRECURSOR_MAJOR_VERSION}.${PRECURSOR_MINOR_VERSION}.${PRECURSOR_PATCH_VERSION}")

project(
    "${PRECURSOR_PROJECT_NAME}"
    VERSION "${PRECURSOR_VERSION}"
    DESCRIPTION "Precursor is a C library for pretty text and formatted output in the terminal"
    HOMEPAGE_URL "https://github.com/patha454/precursor"
    LANGUAGES C
)
include(CTest)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

add_subdirectory(test)

add_library("${PRECURSOR_LIBRARY_NAME}" SHARED
        src/colour.h
        src/terminal.h
        src/colour.c
        src/ansi_terminal.c
        src/ansi_terminal.h
)
target_include_directories("${PRECURSOR_LIBRARY_NAME}" PUBLIC src)

set(PRECURSOR_DEMO_NAME "${PRECURSOR_LIBRARY_NAME}_demo")
add_executable("${PRECURSOR_DEMO_NAME}" demos/demo.c)
target_link_libraries("${PRECURSOR_DEMO_NAME}" "${PRECURSOR_LIBRARY_NAME}")

if (
(${CMAKE_C_COMPILER_ID} STREQUAL "Clang") OR
(${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
)
    target_compile_options("${PRECURSOR_LIBRARY_NAME}" PRIVATE "--pedantic" "-Werror" "-Wall" "-Wextra")
    target_compile_options("${PRECURSOR_DEMO_NAME}" PRIVATE "--pedantic" "-Werror" "-Wall" "-Wextra")
endif ()
