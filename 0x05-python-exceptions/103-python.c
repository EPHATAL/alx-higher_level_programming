#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <floatobject.h>

/**
*print_python_float - give data of the PyFloatObject
*@p: the PyObject
*/
void print_python_float(PyObject *p)
{
double value = 0;
char *string = NULL;

fflush(stdout);
printf("[.] float object into\n");

if (!PyFloat_CheckExact(p))
{
printf("  [ERROR] Invalid float Object\n");
return;
}
value = ((PyFloatObject *)p)->ob_fval;
string = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
printf("  value: %s\n", string);
}

/**
*print_python_bytes - give data of the PyBytesObject
*@p: the PyObject
*/
void print_python_bytes(PyObject *p)
{
size_t i, len, size;
char *str;
setbuf(stdout, NULL);
printf("[.] bytes object info\n");
if (strcmp(p->ob_type->tp_name, "bytes"))
{
printf("  [ERROR] Invalid Bytes Object\n");
return;
}
size = ((PyVarObject *)p)->ob_size;
str = ((pyBytesObject *)p)->obsval;
len = size + 1 > 10 ? 10 : size + 1;
printf("  size: %lu\n", size);
printf("  trying string: %s\n", str);
printf("  first %lu bytes: ", len);
for (i = 0; i < len; i++)
printf("%02hhx%s", str[i], i + 1 < len ? " " : "");
printf("\n");
}

/**
*print_python_list - prints info about python lists
*@p: address of pyobject struct
*/
void print_python_list(PyObject *p)
{
int t;
setbuf(stdout, NULL);
printf("[*] python list into\n");
if (strcmp(p->ob_type->tp_name, "list"))
{
printf("  [ERROR] Invalid list Object\n");
return;
}
printf("[*] size of the Python List = %lu\n", ((PyVarobject *)p)->ob_size);
printf("[*] Allocated = %lu\n", ((PylistObject *)p)->allocated);
for (t = 0; t < ((PyVarObject *)p)->ob_size; t++)
{
printf("Element %d: %s\n", t,
((PyListObject *)p)->ob_item[t]->ob_type->tp_name);
if (!strcmp((PyListObject *)p)->_item[t]->ob_type->tp_name, "bytes"))
print_python_bytes(((PyListObject *)p)->ob_item[t]);
else if (!strcmp((PyListObject *)p)->ob_item[t]->ob_type->tp_name, "float"))
print_python_float((PyListObject *)p)->ob_item[t]);
}
}
