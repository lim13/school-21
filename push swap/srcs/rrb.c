#include "push_swap.h"

void rrb(t_stack **b, int checker)
{
    t_stack *buffer1;
    t_stack *buffer2;
    t_stack *buffer3;

    if (*b == NULL || (*b)->next == NULL)
        return ;
    buffer1 = *b;
    buffer2 = *b;
    while (buffer2->next->next != NULL)
        buffer2 = buffer2->next;
    buffer3 = buffer2->next;
    buffer2->next = NULL;
    buffer3->next = buffer1;
    *b = buffer2;
    if (checker == 1)
        write (1, "rra\n", 4);
}