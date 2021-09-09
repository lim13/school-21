/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:33:41 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:33:46 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_params *count, int checker)
{
	t_stack	*buffer;

	if (count->a == NULL)
		return ;
	buffer = count->a;
	count->a = count->a->next;
	buffer->next = count->b;
	count->b = buffer;
	count->num_of_el_in_b = count->num_of_el_in_b + 1;
	count->num_of_el_in_a = count->num_of_el_in_a - 1;
	if (checker == 1)
		write(1, "pb\n", 3);
}
