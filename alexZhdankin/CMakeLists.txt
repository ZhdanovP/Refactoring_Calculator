cmake_minimum_required(VERSION 2.8)

project(Calculator)

#set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

set(BASE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)
