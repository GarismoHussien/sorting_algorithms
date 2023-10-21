#include "sort.h"

/**
 * swap_ints -this is to  Swap two integers in an array.
 * @a: this is The first integer to swap.
 * @b: this is The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - this is to Sort an array of integers in ascending order
 *                using the selection sort algorithm.
 * @array: ths is An array of integers.
 * @size: this The size of the array.
 *
 * Description:this is to  Print the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
