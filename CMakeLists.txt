cmake_minimum_required(VERSION 3.12)
project(Cpp_LeetCodeCn)

set(CMAKE_CXX_STANDARD 11)

add_executable(T5 longest-palindromic-substring/longest-palindromic-substring.cpp)

add_executable(T4b2 median-of-two-sorted-arrays/better.cpp)

add_executable(T4 median-of-two-sorted-arrays/median-of-two-sorted-arrays.cpp )

add_executable(T3 longest-substring-without-repeating-characters/longest-substring-without-repeating-characters.cpp)

add_executable(T2 add-two-numbers/add-two-numbers.cpp)

add_executable(T1 two-sum/two-sum.cpp)

add_executable(Cpp_LeetCodeCn main.cpp)