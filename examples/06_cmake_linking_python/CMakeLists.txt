cmake_minimum_required(VERSION 3.12)
project(my_prog)

# Find Python
find_package(Python REQUIRED COMPONENTS Development)

# Add the executable
add_executable(my_prog my_prog.cpp)

# Link with Python
target_link_libraries(my_prog PRIVATE Python::Python)