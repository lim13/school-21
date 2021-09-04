
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_stack
{
    int				data;
    struct s_stack	*next;
}					t_stack;

typedef struct      s_counter
{
    int             num_of_el_in_a;
    int             num_of_el_in_b;
}                   t_counter;

typedef struct s_fill
{
    int stack_a[10000];
    int count;
}               t_fill;


void sa(t_stack **a, int checker);
void sb(t_stack **b, int checker);
void ss(t_stack **a, t_stack **b, int checker);
void ra(t_stack **a, int checker);
void rb(t_stack **b, int checker);
void rr(t_stack **a, t_stack **b, int checker);
void rra(t_stack **a, int checker);
void rrb(t_stack **b, int checker);
void rrr(t_stack **a, t_stack **b, int checker);

#endif
