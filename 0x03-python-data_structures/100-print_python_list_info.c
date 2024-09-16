#include <Python.h>
#include <stdio.h>

/**
 * print_python_list_info - Prints basic information about a Python list object.
 * @p: A PyObject representing a Python list.
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, allocated;
    PyObject *item;
    PyListObject *list = (PyListObject *)p;
    int i;

    size = PyList_Size(p);
    allocated = list->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %d: %s\n", i, Py_TYPE(item)->tp_name);
    }
}
