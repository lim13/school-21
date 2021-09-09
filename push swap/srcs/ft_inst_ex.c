/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:28:37 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 22:28:39 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inst_ex(t_params *params, t_moves *moves)
{
	while (moves->a_count > 0)
	{
		if (moves->a_pos == 1)
			ra(&params->a, 1);
		else
			rra(&params->a, 1);
		moves->a_count--;
	}
	while (moves->b_count > 0)
	{
		if (moves->b_pos == 1)
			rb(&params->b, 1);
		else
			rrb(&params->b, 1);
		moves->b_count--;
	}
	pa(params, 1);
}
