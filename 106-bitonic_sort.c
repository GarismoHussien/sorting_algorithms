#include "sort.h"

/**
 * bitonic_recursion - this is recursive function for bitonic sort
 * @array: this is an array to sort
 * @l: this is the index of the left-most element
 * @r: this is the index of the right-most element
 * @direction: this is the ascending or descending
 * @size: this is the size of the array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - this is the sorts and merges 
 *             a sequence in ascending or descending order
 * @array: this is an array to sort
 * @l: this is the index of the left-most element
 * @r: this is index of the right-most element
 * @direction:this is the  ascending or descending
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				tmp = array[i + mid];
				array[i + mid] = array[i];
				array[i] = tmp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}

}
/**
 * bitonic_sort -this is sorts an array following the Bitonic sort algorithm
 * @array: this is an array of ints to sort
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
        if (!array || size < 2)
                return;

        bitonic_recursion(array, 0, size - 1, 1, size);
}
