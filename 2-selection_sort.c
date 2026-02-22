#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_integer - swaps two integer in an
 * array
 * @a: first integer
 * @b: second integer
 * Return: 1 if success, 0 if malfunction
 */

size_t swap_integer(int *a, int *b)
{
	int tmp = 0;

	tmp = *a;
	*a = *b;
	*b = tmp;

	return (1);
}

/**
 * selection_sort - sorts an array of integer
 * using selction sort algorithm
 * @array: array of integer
 * @size: size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	int min = 0;
	int swap_count = 0;

	if (array == NULL)
	{
		return;
	}
	min = array[swap_count];
	for (j = 0; j < size; j++)
	{
		/*befor each loop, set the minimum at the current position*/
		min = array[j];
		/*i = j so that you don't traverse already sorted parts*/
		for (i = j; i < size; i++)
		{
			/* this condition dynamically sets the new minimum*/
			if (min > *(array + i))
			{
				min = *(array + i);
				/*k let you save mininum position in the array*/
				k = i;
			}
		}
		/* this condition prevents a swap at the end of the array*/
		if (*(array + j) > min)
		{
			swap_count += swap_integer((array + j), (array + k));
			print_array(array, size);
		}

	}
}
