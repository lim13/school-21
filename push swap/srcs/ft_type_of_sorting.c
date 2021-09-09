/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_of_sorting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:27:27 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:30:52 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_maximum(t_stack *stack)
{
	int		max;

	max = stack->data;
	while (stack != NULL)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

static void	ft_sort_up_to_three(t_params *params)
{
	int		max;

	if (params->num_of_el_in_a == 1)
		return ;
	if (params->num_of_el_in_a == 2)
	{
		if (params->a->data > params->a->next->data)
			sa(&params->a, 1);
		return ;
	}
	max = ft_maximum(params->a);
	if (params->num_of_el_in_a == 3)
	{
		if (params->a->data == max)
			ra(&params->a, 1);
		if (params->a->next->data == max)
			rra(&params->a, 1);
		if (params->a->data > params->a->next->data)
			sa(&params->a, 1);
	}
}

static void	ft_sort_up_to_five(t_params *params)
{
	while (params->num_of_el_in_b <= 1)
	{
		if (params->a->data == params->min || params->a->data == params->max)
			pb(params, 1);
		else
			ra(&params->a, 1);
	}
	ft_sort_up_to_three(params);
	pa(params, 1);
	pa(params, 1);
	if (params->a->data == params->max)
		ra(&params->a, 1);
	else
	{
		sa(&params->a, 1);
		ra(&params->a, 1);
	}
}

void	ft_type_of_sorting(t_params *params)
{
	if (params->num_of_el_in_a < 4)
		ft_sort_up_to_three(params);
	else if (params->num_of_el_in_a < 6)
		ft_sort_up_to_five(params);
	else if (params->num_of_el_in_a > 5)
		ft_sort_any(params);
}
