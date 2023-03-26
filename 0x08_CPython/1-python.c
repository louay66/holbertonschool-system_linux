#include <stdio.h>
#include <Python.h>

/**
 * print_python_list - prints some basic info about a Python list object
 * @p: a pointer to a PyObject representing a list
 *
 * Return: void
 */
void print_python_list(PyObject *p)
{
	int i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
	printf("[*] Allocated = %ld\n", ((PyListObject *)(p))->allocated);

	for (i = 0; i < PyList_Size(p); i++)
	{
		printf("Element %d: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
	}
}
