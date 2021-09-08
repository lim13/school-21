#include "push_swap.h"

void rrb(t_stack **b, int checker)
{
    t_stack *buffer1;
    t_stack *buffer2;
    t_stack *buffer3;

	if (*b == NULL || (*b)->next == NULL)
        return ;
    buffer1 = *b;
    buffer3 = *b;
    while (buffer3->next->next != NULL)
        buffer3 = buffer3->next;
    buffer2 = buffer3->next;
    buffer3->next = NULL;
    buffer2->next = buffer1;
    *b = buffer2;
    if (checker == 1)
        write (1, "rrb\n", 4);
}