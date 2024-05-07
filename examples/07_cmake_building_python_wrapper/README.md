# Building a C++ library with a Python wrapper using CMake

This example shows how to build a C++ library with a Python wrapper using CMake. In this case, we use `setup_tools` to build the Python wrapper, rather than using `cmake` to build the Python extension directly. This is a simpler approach, which is common for small projects, and is easier to set up and maintain across Python versions.

## Dependencies

You will need `cmake` and `python3` installed. On Mac, you can install these using `brew`:

```bash
brew install cmake python
```

On Ubuntu, you can install these using `apt`:

```bash
sudo apt update
sudo apt install cmake python3
```

On Windows, you can use Visual Studio, or install `cmake` from the [cmake website](https://cmake.org/download/), and `python` from the [python website](https://www.python.org/downloads/windows/) or through [anaconda](https://www.anaconda.com/products/distribution).

## Building

To build the project, run `cmake` and `make` or `nmake` depending on your platform (if you want, you can create a build directory and run `cmake` from there):


Cross-platform Instructions
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Using the wrapper

The build system is set up to create two files in `lib`, a static library also known as  an archive (`libprime.a`) and a python extension (`prime.so` on linux/mac,the actual extension may vary depending on your platform). On Windows, the python extension will be a `.pyd` file.

To use the python wrapper, you can run the following command to add the `lib` directory to the python path:

On Mac/Linux/WSL:
```bash
export PYTHONPATH=$PYTHONPATH:$(pwd)/lib
```

On Windows:
```cmd
set PYTHONPATH=%PYTHONPATH%;%cd%\lib
```

Now start a python interpreter and you can import the `primes` module:
```python
>>> import primes
>>> print(primes.is_prime(7))
>>> print(primes.primes(10)
```

