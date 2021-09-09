/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:51:05 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 19:51:07 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_if_sorted(t_fill *created_list)
{
	int		i;

	i = 0;
	while (i < (created_list->count) - 1)
	{
		if (created_list->stack_a[i] > created_list->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
