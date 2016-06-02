include_directories(../lib/gtest/include ../lib/gtest)
add_executable(hashy_tests hashy_tests.cpp)
target_link_libraries(hashy_tests gtest gtest_main)