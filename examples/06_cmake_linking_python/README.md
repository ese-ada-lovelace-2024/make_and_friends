# Using Python in C++ with CMake

This example shows how to use Python in a C++ program using CMake. In this case, we use `find_package` to locate the Python libraries and include directories, and use `target_link_libraries` to link the Python libraries to the C++ program.

The actual program is set up to read a Python script and exectute a function from inside it, with the names (and arguments) given from the command line.