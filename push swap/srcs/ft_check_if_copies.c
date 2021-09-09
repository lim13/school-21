/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_copies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:47:58 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 19:48:04 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_copy(int *dest, const int *source, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		dest[i] = source[i];
	return (dest);
}

void	ft_check_if_copies(t_fill *created_list, t_params *params)
{
	int		*mas;
	int		j;

	j = 0;
	mas = malloc(sizeof(int) * (created_list->count));
	if (mas == NULL)
		exit (-1);
	mas = ft_copy(mas, created_list->stack_a, created_list->count);
	ft_quicksort(mas, 0, created_list->count - 1);
	while (j != created_list->count - 1)
	{
		if (mas[j] == mas[j + 1])
		{
			write (1, "Error\n", 6);
			exit(1);
		}
		j++;
	}
	params->num_of_el_in_a = created_list->count;
	params->num_of_el_in_b = 0;
	params->median = mas[created_list->count / 2];
	params->max = mas[created_list->count - 1];
	params->min = mas[0];
	free(mas);
}
