
#include "push_swap.h"

void ra(t_stack **a, int checker)
{
    t_stack *buffer1;
    t_stack *buffer2;
    t_stack *buffer3;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    buffer1 = *a;
    buffer2 = (*a)->next;
    buffer3 = *a;
    while (buffer3->next != NULL)
        buffer3 = buffer3->next;
    buffer1->next = NULL;
    buffer3->next = buffer1;
    *a = buffer2;
    if (checker == 1)
        write (1, "ra\n", 3);
}
