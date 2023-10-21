#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints -this is  Swap two integers in an array.
 * @a: this is the first integer to swap.
 * @b: this is the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - this is Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: this is tThe array of integers.
 * @size: this is the size of the array.
 * @left: this is the starting index of the subset to order.
 * @right: this is The ending index of the subset to order.
 *
 * Return: this is the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - this is Implement the quicksort algorithm through recursion.
 * @array: this is An array of integers to sort.
 * @size:this is The size of the array.
 * @left: this is The starting index of the array partition to order.
 * @right: this is The ending index of the array partition to order.
 *
 * Description:this is to  Use the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - this is Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array:this is an array of integers.
 * @size: this is the size of the array.
 *
 * Description: to Use the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
