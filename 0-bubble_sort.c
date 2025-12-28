#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array to sort
 * @size: Number of element in the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	size_t temp = 0;
	size_t initial_size = size;

	for (k = 0; k <= size; k++)
	{
		for (i = 0, j = 1; i <= size; i++, j++)
		{
			if (j == size)
			{
				break;
			}
			if (*(array + i) > *(array + j))
			{
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
				print_array(array, initial_size);
			}
		}
	}
}

