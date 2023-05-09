# `test` is a CMake project that tests the `vec_funcs` library
project(TestExample VERSION 1.0.0 LANGUAGES CXX)

message (STATUS "Configuring tests")

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# Specify some "unit" tests
foreach(TARGET IN ITEMS test_sum test_prod)
    add_executable(${TARGET} ${TARGET}.cpp)
    target_link_libraries(${TARGET} PUBLIC vec_funcs)
    add_test(NAME ${TARGET} COMMAND bin/${TARGET})
endforeach()

add_test(NAME test_calc_sum COMMAND calc sum 1 2 3)

