cmake_minimum_required(VERSION 3.0.0)
project(algodat-datastructures)

# Include directories
include_directories(include)

# Executables
add_executable(exercise_2-1 
    src/array.c
    src/exercise_2-1.c
)
add_executable(exercise_2-2 
    src/list.c
    src/exercise_2-2.c
)
add_executable(exercise_2-3
    src/list.c
    src/stack.c
    src/queue.c
    src/exercise_2-3.c
)
add_executable(exercise_2-4
    src/array.c
    src/list.c
    src/queue.c
    src/binary_tree.c
    src/exercise_2-4.c
)