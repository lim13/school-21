
#include "push_swap.h"

void pa(t_stack **a, t_stack **b, t_params *count, int checker)
{
    t_stack *buffer;

    if (*b == NULL)
        return ;
    buffer = *b;
    *b = (*b)->next;
    buffer->next = *a;
    *a = buffer;
    count->num_of_el_in_a = count->num_of_el_in_a + 1;
    count->num_of_el_in_b = count->num_of_el_in_b - 1;
    if (checker == 1)
        write (1, "pa\n", 3);
}

