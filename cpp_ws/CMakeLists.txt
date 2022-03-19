# Declare the version of the CMake API for forward-compatibilit
cmake_minimum_required(VERSION 3.1)
# set_property(CMAKE_CXX_STANDARD 17)

# Declare the name of the Cmake Project
project(LeetCode)

# Add the directory to search for header files
include_directories(include)

# Define executable targets
add_executable(1_two_sum src/1_two_sum.cpp)
add_executable(242_valid_anagram src/242_valid_anagram.cpp)
add_executable(349_intersection_of_two_arrays src/349_intersection_of_two_arrays.cpp)
add_executable(1002_find_common_characters src/1002_find_common_characters.cpp)