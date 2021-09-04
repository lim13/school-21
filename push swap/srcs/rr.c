#include "push_swap.h"

void rr(t_stack **a, t_stack **b, int checker)
{
    ra(a, 0);
    rb(b, 0);
    if (checker == 1)
        write(1, "rr\n", 3);
}