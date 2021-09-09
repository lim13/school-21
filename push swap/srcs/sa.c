/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:52:50 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/26 16:52:52 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int checker)
{
	int	buffer;

	buffer = 0;
	if (*a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	buffer = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = buffer;
	if (checker == 1)
		write(1, "sa\n", 3);
}
