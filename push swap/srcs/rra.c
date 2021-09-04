#include "push_swap.h"

void rra(t_stack **a, int checker)
{
    t_stack *buffer1;
    t_stack *buffer2;
    t_stack *buffer3;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    buffer1 = *a;
    buffer2 = *a;
    while (buffer2->next->next != NULL)
        buffer2 = buffer2->next;
    buffer3 = buffer2->next;
    buffer2->next = NULL;
    buffer3->next = buffer1;
    *a = buffer2;
    if (checker == 1)
        write (1, "rra\n", 4);
}