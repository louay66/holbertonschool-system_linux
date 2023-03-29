#include <stdio.h>
#include <float.h>
#include "string.h"
#include <Python.h>

/**
 * print_python_float - prints some basic info about a Python float object
 * @p: a pointer to a PyObject representing a float object
 *
 * Return: void
 */
void print_python_float(PyObject *p)
{
	char *str;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if (!p || !PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	str = PyOS_double_to_string(((PyFloatObject *)p)->ob_fval,
			'g', 16, 0, NULL);
	printf("  value: %s%s\n", str, strchr(str, '.') ? "" : ".0");
}

/**
 * print_python_bytes - prints some basic info about a Python bytes object
 * @p: a pointer to a PyObject representing a bytes object
 *
 * Return: void
 */
void print_python_bytes(PyObject *p)
{
	int i;
	Py_ssize_t size, printed_bytes;
	char *array_as_string = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %li\n", size);

	array_as_string = ((PyBytesObject *)(p))->ob_sval;
	printf("  trying string: %s\n", array_as_string);

	printed_bytes = (size + 1 >= 10) ? 10 : size + 1;
	printf("  first %li bytes:", printed_bytes);
	for (i = 0; i < printed_bytes; i++)
		printf(" %02x", (unsigned char)(array_as_string[i]));
	putchar('\n');
}
/**
 * print_python_list - prints some basic info about a Python list object
 * @p: a pointer to a PyObject representing a list
 *
 * Return: void
 */
void print_python_list(PyObject *p)
{
	PyObject *item;
	int i;

	if (!p)
		return;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", PyList_Size(p));
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < PyList_Size(p); i++)
	{
		item = ((PyListObject *)(p))->ob_item[i];
		printf("Element %d: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
		else if (PyFloat_Check(item))
			print_python_float(item);
	}
}
