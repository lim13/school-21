
#include "push_swap.h"

void ss(t_stack **a, t_stack **b, int checker)
{
    sa(a, 0);
    sb(b, 0);
    if (checker == 1)
        write(1, "ss\n", 3);
}