nclude "sort.h"

/**
 * swap_ints -ithis to Swap two integers in an array.
 * @a: this  is the first integer to swap.
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
 * bubble_sort -this is Sort an array of integers in ascending order.
 * @array: this is An array of integers to sort.
 * @size: this is The size of the array.
 *
 * Description: this is to Print the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
