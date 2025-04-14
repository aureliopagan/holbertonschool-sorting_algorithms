#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble Sort algorithm.
 * @array: A pointer to the first element of the array
 * @size: The size of the array
 *
 * Description: This function sorts the array using Bubble Sort.
 *              It repeatedly swaps adjacent elements if they are
 *              in the wrong order.
 */
void bubble_sort(int *array, size_t size)
{
	int temp_val;
	int has_swapped;
	size_t outer, inner;

	for (outer = 0; outer < size - 1; outer++)
	{
		has_swapped = 0;
		for (inner = 0; inner < size - 1 - outer; inner++)
		{
			if (array[inner] > array[inner + 1])
			{
				/* Swap elements */
				temp_val = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp_val;

				has_swapped = 1;
				print_array(array, size);
			}
		}
		if (!has_swapped)
			break;
	}
}

