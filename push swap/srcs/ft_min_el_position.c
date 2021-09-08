#include "push_swap.h"

int		ft_min_el_position(t_stack *a, int min)
{
    int i;

    i = 0;
    while (a)
    {
        if (a->data == min)
            break ;
        a = a->next;
        i++;
    }
    return (i);
}
