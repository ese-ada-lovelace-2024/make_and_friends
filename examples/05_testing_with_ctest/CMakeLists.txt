cmake_minimum_required(VERSION 3.10)

# set the project name (and the name f)
project(TestExample)LINK_FLAGS

# add the library
add_library(sum_func STATIC sum_func.cpp)

add_executable(test_sum tests/test_sum)
set_target_properties(test_sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY tests/bin)
target_link_libraries(test_sum PUBLIC sum_func)
enable_testing()
add_test(NAME SumTest COMMAND tests/bin/test_sum)