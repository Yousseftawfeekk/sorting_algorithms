#include "sort.h"

/**
 * swap - Swap two ints
 * @max: The max integer to swap.
 * @min: The min integer to swap.
 */

void swap(int *max, int *min)
{
	int replace;

	replace = *max;
	*max = *min;
	*min = replace;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *
 * @array: array of integers
 * @size: The size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t G, i, j;

	if (!array || size < 2)
		return;

	for (G = 1; G < (size / 3);)
		G = (G * 3) + 1;

	for (; G >= 1; G /= 3)
	{
		for (i = G; i < size; i++)
		{
			j = i;
			while (j >= G && array[j - G] > array[j])
			{
				swap(array + j, array + (j - G));
				j -= G;
			}
		}
		print_array(array, size);
	}
}
