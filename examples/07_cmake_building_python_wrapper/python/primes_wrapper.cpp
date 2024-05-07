#include <Python.h>

#include "primes.h"

#include <vector>
#include <iostream>

extern "C" {
    static PyObject* primes_wrapper(PyObject* self, PyObject* args);
    static PyObject* is_prime_wrapper(PyObject* self, PyObject* args);
}

static PyObject* primes_wrapper(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    std::vector<long> result = primes(n);

    PyObject* py_result = PyList_New(n);
    for (size_t i = 0; i < result.size(); i++)
    {
        PyObject* py_long = PyLong_FromLong(result[i]);
        PyList_SetItem(py_result, i, py_long);
    }
    return py_result;
}

static PyObject* is_prime_wrapper(PyObject* self, PyObject* args)
{
    long n;
    int construct = 50;
    if (!PyArg_ParseTuple(args, "l|i", &n, &construct))
        return NULL;

    bool result = is_prime(n, construct);
    return PyBool_FromLong(result);

}

static PyMethodDef primes_module_methods[] = {
    {"primes", primes_wrapper, METH_VARARGS, "Returns a list of the first n prime numbers"},
    {"is_prime", is_prime_wrapper, METH_VARARGS, "Returns True if n is prime, False otherwise"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef primes_module = {
    PyModuleDef_HEAD_INIT,
    "primes",
    "A module for prime number generation and testing",
    -1,
    primes_module_methods
};

PyMODINIT_FUNC PyInit_primes(void)
{
    return PyModule_Create(&primes_module);
}