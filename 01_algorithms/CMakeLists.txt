cmake_minimum_required(VERSION 3.0.0)
project(algodat-algortihms)

# Include directories
include_directories(include)

# Executables
add_executable(exercise_1-2 
    src/guessing_game.c
    src/exercise_1-2.c
)

add_executable(exercise_1-3 
    src/guessing_game.c
    src/exercise_1-3.c
)

add_executable(example_factorial 
    src/factorial.c
    src/example_factorial.c
)

add_executable(example_hanoi
    src/hanoi.c
    src/example_hanoi.c
)