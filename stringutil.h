#include <stdio.h>
#include <malloc.h>

char* int_array_to_string(int*, int, char);
// array of integer string size
int static size_table[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 0x7FFFFFFF};

// get the string of the int parameter
unsigned string_size(int);
