/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:52:27 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:52:29 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				move;
	int				rot;
	struct s_stack	*next;
}					t_stack;

typedef struct s_params
{
	t_stack			*a;
	t_stack			*b;
	int				num_of_el_in_a;
	int				num_of_el_in_b;
	int				min;
	int				max;
	int				median;
}					t_params;

typedef struct s_fill
{
	int				stack_a[10000];
	int				count;
}					t_fill;

typedef struct s_moves
{
	int				a_count;
	int				b_count;
	int				a_pos;
	int				b_pos;
}					t_moves;

void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b, int checker);
void	pa(t_params *count, int checker);
void	pb(t_params *count, int checker);
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b, int checker);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b, int checker);
int		ft_check_data(int argc, char **argv);
void	ft_str_to_num_array(int argc, char **argv, t_fill *created_list);
void	ft_check_if_copies(t_fill *created_list, t_params *params);
void	ft_quicksort(int *array, int first, int last);
int		ft_check_if_sorted(t_fill *created_list);
void	ft_initialization(t_fill *created_list, t_params *params);
void	ft_type_of_sorting(t_params *params);
void	ft_sort_any(t_params *params);
int		ft_min_el_position(t_stack *a, int min);
int		ft_find_right_pos(t_params *count, t_stack *b, t_moves *moves, int min);
void	ft_inst_ex(t_params *params, t_moves *moves);

#endif
