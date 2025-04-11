#include "sort.h"
#include <stddef.h>

/**
 * swap - swap two value by address
 * @a: value swap
 * @b: value swap
 * Return: just swap
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_part - partition array according lomuto
 * @array: array to partition
 * @low: begin position
 * @high: last
 * @size: size of array
 * Return: no needed just sort
 */

int lomuto_part(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
			else
				swap(&array[j], &array[i]);
			i++;
		}
	}
	if (i != high && array[i] != array[high])
	{
		swap(&array[high], &array[i]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_rc - algorythm recurcive quicl sort
 * @array: array to sort
 * @low: begin position of array sorted
 * @high: last
 * @size: size total of array(cant do without)
 * Return: no needed just sort
 */

void quick_sort_rc(int *array, int low, int high, size_t size)
{
	int index_p;

	if (low < high)
	{
		index_p = lomuto_part(array, low, high, size);
		quick_sort_rc(array, low, index_p - 1, size);
		quick_sort_rc(array, index_p + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm with implement the Lomuto partition scheme.
 * @array: array to sort
 * @size: size of array
 * Return: no needed just sort
 */

void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_rc(array, 0, size - 1, size);
}
