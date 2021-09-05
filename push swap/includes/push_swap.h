
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

typedef struct      s_params
{
	t_stack			*a;
	t_stack			*b;
    int             num_of_el_in_a;
    int             num_of_el_in_b;
	int				min;
	int				max;
	int 			median;
}                   t_params;

typedef struct 		s_fill
{
    int 			stack_a[10000];
    int 			count;
}               	t_fill;

void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b, int checker);
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b, int checker);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b, int checker);
int	ft_check_data(int argc, char **argv);
void	ft_str_to_num_array(int argc, char **argv, t_fill *created_list);
void	ft_check_if_copies(t_fill *created_list, t_params *params);
void	ft_quicksort(int *array, int first, int last);

#endif
