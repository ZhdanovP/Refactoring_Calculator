cmake_minimum_required(VERSION 2.8)

project(Monopoly)

set(CMAKE_CXX_COMPILER "/usr/bin/g++-9")
SET(CMAKE_CXX_FLAGS "-g -std=c++17")

enable_testing()

set(BASE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)
