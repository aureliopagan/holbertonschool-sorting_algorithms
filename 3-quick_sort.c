#include "sort.h"

/**
 * partition_array - Divides the array into smaller segments based on pivot
 * @array: Array to be sorted
 * @low: Lower index of the segment
 * @high: Higher index of the segment
 * @size: Size of the full array
 *
 * Return: The index of the pivot element after partitioning
 */
int partition_array(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp_value;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp_value = array[i];
				array[i] = array[j];
				array[j] = temp_value;
				print_array(array, size);
			}
		}
	}

	/* Move pivot to correct position */
	if (array[i + 1] > pivot)
	{
		temp_value = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp_value;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursion - Sorts the array recursively using QuickSort
 * @array: The array to be sorted
 * @low: The lower index of the array segment
 * @high: The higher index of the array segment
 * @size: Size of the array
 *
 * Return: None
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_array(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Wrapper function to initiate the sorting process
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	low = 0;
	high = size - 1;

	if (size < 2 || array == NULL)
		return;

	quick_sort_recursion(array, low, high, size);
}

