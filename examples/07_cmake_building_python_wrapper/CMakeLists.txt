cmake_minimum_required(VERSION 3.16)

project(ExampleWithTests VERSION 1.0)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(primes STATIC ${CMAKE_SOURCE_DIR}/src/primes.cpp)

set_target_properties(primes PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
                                        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

#add_executable(test_primes ${CMAKE_SOURCE_DIR}/src/test_primes.cpp)

#target_link_libraries(test_primes primes)

add_custom_target(wrapper ALL
                          COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/python/setup.py build_ext --build-lib ${CMAKE_BINARY_DIR}/lib
                          WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/python
                          SOURCES ${CMAKE_SOURCE_DIR}/python/setup.py ${CMAKE_SOURCE_DIR}/python/primes_wrapper.cpp)

add_dependencies(wrapper primes)

add_custom_target(install-wrapper COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/python/setup.py install
                          WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/python
                          SOURCES ${CMAKE_SOURCE_DIR}/python/setup.py ${CMAKE_SOURCE_DIR}/python/primes_wrapper.cpp
                          DEPENDS wrapper)

# Command to clean the wrapper
add_custom_target(clean-wrapper COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/python/setup.py clean && cmake -E remove ${CMAKE_BINARY_DIR}/lib/primes.*.so
                          WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/python
                          SOURCES ${CMAKE_SOURCE_DIR}/python/setup.py ${CMAKE_SOURCE_DIR}/python/primes_wrapper.cpp)