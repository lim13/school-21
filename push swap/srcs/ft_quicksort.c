
#include "push_swap.h"

static int ft_arrange(int *array, int first, int last)
{
    int i;
    int j;
    int buf;

    i = first - 1;
    j = first;
    while (j < last)
    {
        if (array[j] <= array[last])
        {
            i++;
            buf = array[i];
            array[i] = array [j];
            array[j] = buf;
        }
        j++;
    }
    buf = array[i + 1];
    array[i + 1] = array[last];
    array[last] = buf;
    return (i + 1);
}

void ft_quicksort(int *array, int first, int last)
{
	int i;

	if (first < last)
	{
        i = ft_arrange(array, first, last);
        ft_quicksort(array, first, i - 1);
        ft_quicksort(array, i + 1, last);
	}
}