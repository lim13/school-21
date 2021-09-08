
#include "push_swap.h"

int     ft_check_if_sorted(t_fill *created_list)
{
    int i;

    i = 0;
    while (i < (created_list->count) - 1)
    {
        if (created_list->stack_a[i] > created_list->stack_a[i + 1])
            return (1);
        i++;
    }
    return (0);
}

