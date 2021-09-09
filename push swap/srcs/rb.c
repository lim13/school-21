/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:39:49 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:39:54 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b, int checker)
{
	t_stack	*buffer1;
	t_stack	*buffer2;
	t_stack	*buffer3;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	buffer1 = *b;
	buffer2 = (*b)->next;
	buffer3 = *b;
	while (buffer3->next != NULL)
		buffer3 = buffer3->next;
	buffer1->next = NULL;
	buffer3->next = buffer1;
	*b = buffer2;
	if (checker == 1)
		write(1, "rb\n", 3);
}
