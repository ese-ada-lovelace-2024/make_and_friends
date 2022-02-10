cmake_minimum_required(VERSION 3.10)

project (openmp-cmake)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
 
add_executable(omp_ex main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(omp_ex PUBLIC OpenMP::OpenMP_CXX)
endif()