#include <stdio.h>
#include "stringutil.h"

int main(void)
{
	int t[5] = {1, 99, 30000, 42, 500};
	char* str_of_t = int_array_to_string(t, 5, ',');
	printf("the result of the array t is: %s\n", str_of_t);

	printf("max value of int in 0x7FFFFFFF is: %d\n", 0x7FFFFFFF);
	printf("max value of unsigned in 0xFFFFFFFF is: %u\n", 0xFFFFFFFF);
	return 0;
}

/*
 * n: number will be counted string size
 * */
unsigned string_size(int n)
{
	// return the width or else return the max value
	// of the unsigned
	for (unsigned i = 0; ; i++)
		if (n <= size_table[i])	
			return i+1;
	return 0xFFFFFFFF;
}


/** 
 * arr: the head pointer of int array
 * len: length of array
 * delimiter: delimiter of output number string 
**/ 
char* int_array_to_string(int* arr, int len, char delimiter)
{
	// string length
	unsigned whole_length = 0;
	// temp store char array
	char** store = NULL;
	// for each number the header pointer
	store = (char**)malloc(sizeof(char*)*len);
	// check the whether the pointer is NULL or not
	// so do len
	if (!arr || len <= 0)
		return NULL;
	for (int ii = 0; ii < len; ii++)
	{
		unsigned l = string_size(arr[ii]);	
		char* num_buf = (char*)malloc(l + 1);	
		// store the length
		num_buf[0] = l;
		sprintf(num_buf + 1, "%d", arr[ii]);
		// printf("each buf num is: %s\n", num_buf + 1);
		store[ii] = num_buf;
		// accumulate each number length
		whole_length += l;
	}
	// printf("whole length: %u\n", whole_length);
	// len + 2 is from len - 1 + 3
	unsigned ll = (whole_length + ( len - 1 ) + 3);
	// more memory for space and '\0', [, ]
	char* result_string = (char*)malloc(sizeof(char) * ll );
	result_string[0] = '[';
	for (int jj = 0, l = 0; jj < len && l < ll - 2; jj++)
	{
		// get each character from store to result
		// get the string size of each number
		for(int kk = 1; kk <= store[jj][0]; kk++)
		{
			result_string[++l] = store[jj][kk];
		}
		// add the space
		result_string[++l] = delimiter;
		// free the sub temp store
		free(store[jj]);
	}
	// free the whole store
	free(store);
	result_string[ll - 2] = ']';
	// don't forget to add the limitation of string
	result_string[ll - 1] = '\0';
	return result_string;
}
