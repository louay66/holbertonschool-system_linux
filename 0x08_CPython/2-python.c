#include <stdio.h>
#include <Python.h>

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
		printf("Element %ld: %s\n", i, item->ob_type->tp_name);
		if (PyBytes_Check(item))
			print_python_bytes(item);
	}
}
