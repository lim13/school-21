/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:02:34 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:02:36 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_find_el_min_moves_send(t_params *params, t_moves *moves)
{
	int		min_moves;
	t_stack	*top_a;
	t_stack	*top_b;

	min_moves = -1;
	top_a = params->a;
	top_b = params->b;
	while (params->b)
	{
		min_moves = ft_find_right_pos(params, params->b, moves, min_moves);
		params->a = top_a;
		params->b = params->b->next;
	}
	params->b = top_b;
}

static void	ft_num_of_moves_to_top(t_stack *b, int num)
{
	int		i;
	t_stack	*tmp;
	int		counter;

	i = -1;
	tmp = b;
	counter = num / 2;
	while (++i <= counter)
	{
		tmp->move = i;
		tmp->rot = 1;
		tmp = tmp->next;
	}
	if (num % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->move = i;
		tmp->rot = -1;
		tmp = tmp->next;
	}
}

static void	ft_circle_sec(t_params *params, t_moves *move)
{
	move->a_count = -1;
	move->b_count = -1;
	move->a_pos = 0;
	move->b_pos = 0;
	ft_num_of_moves_to_top(params->a, params->num_of_el_in_a);
	ft_num_of_moves_to_top(params->b, params->num_of_el_in_b);
	ft_find_el_min_moves_send(params, move);
	ft_inst_ex(params, move);
}

static void	ft_begin_sorting(t_params *params)
{
	t_moves	*move;

	move = (t_moves *)malloc(sizeof(t_moves));
	if (move == NULL)
		exit(1);
	while (params->num_of_el_in_b != 0)
		ft_circle_sec(params, move);
	if ((ft_min_el_position(params->a, params->min)) > params->num_of_el_in_a
		/ 2)
	{
		while (params->a->data != params->min)
			rra(&params->a, 1);
	}
	else
	{
		while (params->a->data != params->min)
			ra(&params->a, 1);
	}
	free(move);
}

void	ft_sort_any(t_params *params)
{
	while (params->num_of_el_in_a > 2)
	{
		if (params->a->data != params->min && params->a->data != params->max)
		{
			pb(params, 1);
			if (params->b->data > params->median)
				rb(&params->b, 1);
		}
		else
			ra(&params->a, 1);
	}
	if (params->a->data < params->a->next->data)
		sa(&params->a, 1);
	pa(params, 1);
	ft_begin_sorting(params);
}
