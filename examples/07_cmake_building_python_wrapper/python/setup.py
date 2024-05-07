from setuptools import setup, Extension

# define the extension module
primes_module = Extension('primes',
                          sources=['primes_wrapper.cpp'],
                          libraries=['primes'],
                          library_dirs=['../lib'],
                          include_dirs=['../include'])

# run the setup
setup(
    name='Primes',
    version='1.0',
    description='Python Package with C Extension for prime calculations',
    ext_modules=[primes_module]
)