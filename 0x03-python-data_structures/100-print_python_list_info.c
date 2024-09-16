#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_python_list_info - Prints basic info about Python lists
 * @p: Pointer to a Python object, which should be a list
 */
void print_python_list_info(PyObject *p)
{
Py_ssize_t size, i;
PyObject *item;

/* Ensure the object is a list */
if (!PyList_Check(p))
{
fprintf(stderr, "Object is not a list\n");
return;
}
/* Get size of the list */
size = PyList_Size(p);
/* Print size and allocated size */
printf("[*] Size of the Python List = %ld\n", size);
printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
/* Loop through the list and print element types */
for (i = 0; i < size; i++)
{
item = PyList_GetItem(p, i);
printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
}
}
