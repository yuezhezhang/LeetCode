# Declare the version of the CMake API for forward-compatibilit
cmake_minimum_required(VERSION 3.1)
# set_property(CMAKE_CXX_STANDARD 17)

# Declare the name of the Cmake Project
project(LeetCode)

# Add the directory to search for header files
include_directories(include)

# Define executable targets
add_executable(0001_two_sum src/0001_two_sum.cpp)
add_executable(0242_valid_anagram src/0242_valid_anagram.cpp)
add_executable(0349_intersection_of_two_arrays src/0349_intersection_of_two_arrays.cpp)
add_executable(1002_find_common_characters src/1002_find_common_characters.cpp)
add_executable(0202_happy_number src/0202_happy_number.cpp)
add_executable(0454_4_sum_2 src/0454_4_sum_2.cpp)
add_executable(0383_ransom_note src/0383_ransom_note.cpp)