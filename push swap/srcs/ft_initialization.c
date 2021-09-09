/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:56:53 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 19:56:54 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialization(t_fill *created_list, t_params *params)
{
	int			i;
	t_stack		*newlist;
	t_stack		*firstel;

	i = 0;
	params->b = NULL;
	newlist = malloc(sizeof(t_stack));
	if (newlist == NULL)
		exit (1);
	firstel = newlist;
	while (i < created_list->count)
	{
		if (i < created_list->count - 1)
			newlist->next = (t_stack *)malloc(sizeof(t_stack));
		if (i < created_list->count - 1)
			if (newlist->next == NULL)
				exit (1);
		newlist->data = created_list->stack_a[i];
		if (i == created_list->count - 1)
			newlist->next = NULL;
		else
			newlist = newlist->next;
		i++;
	}
	params->a = firstel;
}
