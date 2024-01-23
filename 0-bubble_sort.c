#include "sort.h"

/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	int replace;
	size_t i = 0;
	size_t b = 0;

	if (!array || !size)
	{
		return;
	}

	while (i < size)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				replace = array[b];
				array[b] = array[b + 1];
				array[b + 1] = replace;
				print_array(array, size);
			}
		}
		i++;
	}
}
