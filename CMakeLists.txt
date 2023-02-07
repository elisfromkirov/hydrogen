cmake_minimum_required(VERSION 3.21)
project(hydrogen CXX ASM)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(third_party)