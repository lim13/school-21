#include "push_swap.h"

void sa(t_stack **b, int checker)
{
    int buffer;

    buffer = 0;
    if (*b == NULL)
        return ;
    if ((*b)->next == NULL)
        return;
    buffer = (*b)->data;
    (*b)->data = (*b)->next->data;
    (*b)->next->data = buffer;
    if (checker == 1)
        write(1, "sb\n", 3);
}
