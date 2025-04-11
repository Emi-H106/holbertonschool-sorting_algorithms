#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	int i, pivot, tmp;
	size_t j;
	size_t left_size;
	size_t right_size;

	if (!array || size < 2)
		return;
	pivot = array[size - 1]; /* Choose the last element as pivot */
	i = -1; /* less than pivot */
	for (j = 0; j < size - 1; j++) /* Partitioning the array */
	{
		if (array[j] < pivot)
		{
			i++;
			if ((size_t)i != j)
			{
				/* Swap elements */
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				/* Print the array after swap */
				print_array(array, size);
			}
		}
	}
	if ((size_t)(i + 1) != size - 1) /* Place the pivot in its correct position */
	{
		tmp = array[i + 1];
		array[i + 1] = array[size - 1];
		array[size - 1] = tmp;
		print_array(array, size);
	}
		/* Recursively sort the left and right sub-arrays */
	left_size = i + 1;
	right_size = size - left_size - 1;
	if (left_size > 1) /* Sort the sub-array to the left of the pivot */
		quick_sort(array, left_size);
	if (right_size > 1) /* Sort the sub-array to the right of the pivot */
		quick_sort(array + left_size + 1, right_size);
}
