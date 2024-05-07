# Examples

This folder contains examples of the use of Makefiles and CMake to configure and build C++ code.

- [00_hello_world](00_hello_world/README.md): A simple hello world program, with bash and batch scripts to build it.
- [01_makefile_for_hello_world](01_makefile_for_hello_world/README.md): An example Makefile for a hello world program.
- [02_makefile_for_biscuits](02_makefile_for_biscuits/README.md): An example Makefile for a program with multiple source files.
- [03_cmake_for_hello_world](03_cmake_for_hello_world/README.md): An example CMakeLists.txt for a hello world program to build using CMake.
- [04_cmake_for_mpi](04_cmake_for_mpi/README.md): An example CMakeLists.txt for a MPI parallel program to build using CMake.
- [05_cmake_for_openmp](05_cmake_for_openmp/README.md): An example CMakeLists.txt for a OpenMP parallel program to build using CMake.
- [06_cmake_linking_python](06_cmake_linking_python/README.md): An example CMakeLists.txt for a C++ program which links to Python.
- [07_cmake_building_python_wrapper](07_cmake_building_python_wrapper/README.md): An example CMakeLists.txt for a C++ program which builds a Python wrapper for a C++ library. In this case, we use `setup_tools` to build the Python wrapper.
- [08_testing_with_ctest](08_testing_with_ctest/README.md): An example CMakeLists.txt for a C++ program which uses CTest for testing.
- [09_autoconf_for_hello_world](09_autoconf_for_hello_world/README): For completeness, an example `configure.ac` and `Makefile.am` for a hello world program to build using autoconf. Note that `autoconf/autotools` is only relevant on linux (including WSL) and mac, and is not natively supported on Windows.