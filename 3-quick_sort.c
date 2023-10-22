#include "sort.h"

/**
 * swap -the swaps 2 int values
 * @array: this is the integer array to sort
 * @size: this is the size of the array
 * @a: the address of first value
 * @b:the  address of second value
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - the partitions of the array
 * @array: this is the integer array to sort
 * @size: this is the size of the array
 * @lo: this is the low index of the sort range
 * @hi: this is the high index of the sort range
 *
 * Return: void
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort - this is the quicksorts via Lomuto partitioning scheme
 * @array: this is the integer array to sort
 * @size: this is the size of the array
 * @lo: this is the low index of the sort range
 * @hi: this is the high index of the sort range
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - this is calls quicksort
 * @array: this is the integer array to sort
 * @size: this is the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
