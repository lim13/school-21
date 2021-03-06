/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:32:22 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:32:26 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_params *count, int checker)
{
	t_stack	*buffer;

	if (count->b == NULL)
		return ;
	buffer = count->b;
	count->b = count->b->next;
	buffer->next = count->a;
	count->a = buffer;
	count->num_of_el_in_a = count->num_of_el_in_a + 1;
	count->num_of_el_in_b = count->num_of_el_in_b - 1;
	if (checker == 1)
		write (1, "pa\n", 3);
}
