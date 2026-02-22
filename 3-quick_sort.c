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
 * real_quick_sort - actually do the f*** work
 * @array: Original array
 * @size: Original size
 * @start_point: Beginning of sorting
 * @lenght: portion to sort
 * Return: void
 */

void real_quick_sort(int *array, size_t size, int *start_point, size_t lenght)
{
	size_t i = 0;
	size_t j = 0;
	int pivot = 0;

	if (lenght < 2)
	{
		return;
	}

	pivot = start_point[(lenght - 1)];

	for (j = 0, i = 0; j < lenght; j++)
	{
		if (*(start_point + j) <= pivot)
		{
			swap_integer((start_point + i), (start_point + j));
			print_array(array, size);
			i++;
		}
	}

	real_quick_sort(array, size, start_point, i - 1);
	real_quick_sort(array, size, (start_point + i), (lenght - i));
}
/**
 * quick_sort - sort an array of
 * integer using quick sort algo
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */


void quick_sort(int *array, size_t size)
{
	real_quick_sort(array, size, array, size);
}
