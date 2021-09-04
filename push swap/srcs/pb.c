
#include "push_swap.h"

void pa(t_stack **a, t_stack **b, t_counter *count, int checker)
{
    t_stack *buffer;

    if (*a == NULL)
        return ;
    buffer = *a;
    *a = (*a)->next;
    buffer->next = *b;
    *b = buffer;
    count->num_of_el_in_b = count->num_of_el_in_b + 1;
    count->num_of_el_in_a = count->num_of_el_in_a - 1;
    if (checker == 1)
        write(1, "pb\n", 3);
}

