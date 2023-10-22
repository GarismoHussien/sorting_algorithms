#include "sort.h"

/**
 * quick_sort_hoare - to sort an array with the Quicksort algorithm
 * @array: this is the array of ints to sort
 * @size: this is the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - the helper function for Quicksort
 * @array: this is the array to sort
 * @left: this is the index of the left element
 * @right: this is the index of the right element
 * @size: this is the size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv, right, size);
	}
}

/**
 * partition - this is to give a piv index for Quicksort
 * @array: this is the array to find the piv in
 * @left: this is the index of the left element
 * @right: this is the index of the right element
 * @size: this is the size of the array
 *
 * Return: this is the index of the piv element
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t i, j;

	i = left - 1;
	j = right + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	return (0);
}
