cmake_minimum_required(VERSION 3.10)

# set the project name (and optionally define its version)
project(ExampleWithTests VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR})

# add our library
add_library(vec_funcs STATIC vec_funcs.cpp vec_funcs.h)

# add the executable
add_executable(toycalc toycalc.cpp vec_funcs.h)
target_link_libraries(toycalc PUBLIC vec_funcs)

include_directories(${CMAKE_SOURCE_DIR})
enable_testing()
add_subdirectory(tests)