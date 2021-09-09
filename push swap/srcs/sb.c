/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:44:42 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:44:43 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int checker)
{
	int	buffer;

	buffer = 0;
	if (*b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	buffer = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = buffer;
	if (checker == 1)
		write(1, "sb\n", 3);
}
