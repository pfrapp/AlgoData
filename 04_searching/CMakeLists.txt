cmake_minimum_required(VERSION 3.0.0)
project(algodat-searching)

# Include directories
include_directories(include)

# Executables
add_executable(example_listsearch
    src/example_listsearch.c
    src/listsearch.c
)
add_executable(example_strfind
    src/example_strfind.c
    src/strfind.c
)