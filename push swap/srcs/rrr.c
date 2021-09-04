#include "push_swap.h"

void rrr(t_stack **a, t_stack **b, int checker)
{
    rra(a, 0);
    rrb(b, 0);
    if (checker == 1)
        write(1, "rrr\n", 3);
}
