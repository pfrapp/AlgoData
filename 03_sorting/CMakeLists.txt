cmake_minimum_required(VERSION 3.0.0)
project(algodat-sorting)

# Include directories
include_directories(include)

# Executables
add_executable(exercise_3-1 
    src/array_utility.c
    src/bubblesort.c
    src/insertsort.c
    src/selectsort.c
    src/exercise_3-1.c
)

add_executable(example_3-2 
    src/array_utility.c
    src/heapsort.c
    src/mergesort.c
    src/quicksort.c
    src/example_3-2.c
)