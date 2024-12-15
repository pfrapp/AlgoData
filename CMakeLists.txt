cmake_minimum_required(VERSION 3.14.0)
project(algodat)

# Set this if you are builing on Apple Silicon.
set(CMAKE_OSX_ARCHITECTURES "arm64")

# --- Subdirectories ---
add_subdirectory(01_algorithms)
add_subdirectory(02_datastructures)
add_subdirectory(03_sorting)
add_subdirectory(04_searching)