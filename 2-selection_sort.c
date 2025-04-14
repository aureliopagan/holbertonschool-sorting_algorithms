#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function repeatedly selects the smallest element from
 * the unsorted portion of the array and swaps it with the first unsorted element.
 */
void selection_sort(int *array, size_t size)
{
	size_t outer, inner, min_index;
	int temp_value;

	for (outer = 0; outer < size - 1; outer++)
	{
		min_index = outer;
		for (inner = outer + 1; inner < size; inner++)
		{
			if (array[inner] < array[min_index])
			{
				min_index = inner;
			}
		}

		if (min_index != outer)
		{
			/* Swap the elements */
			temp_value = array[outer];
			array[outer] = array[min_index];
			array[min_index] = temp_value;

			/* Print the array after the swap */
			print_array(array, size);
		}
	}
}

