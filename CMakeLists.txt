cmake_minimum_required(VERSION 3.4)
project(hashy_table)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")

set(SOURCE_FILES main.c hashtable/hashtable.h)
add_executable(hashy_table ${SOURCE_FILES})

add_subdirectory(hashtable)
add_subdirectory(hashtable_tests)