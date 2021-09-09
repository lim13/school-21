/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_num_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 20:24:08 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/09 20:24:11 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_numbers(char const *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			count++;
			while ((str[i] != '\0') && (str[i] != '\t') && (str[i] != ' '))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_use_atoi(int *tmp, char **array, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		tmp[j] = ft_atoi(array[j]);
		free(array[j]);
		j++;
	}
	return (*tmp);
}

void	ft_str_to_num_array(int argc, char **argv, t_fill *created_list)
{
	char	**array;
	int		i;
	int		j;
	int		count;
	int		*tmp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		count = ft_count_numbers(argv[i]);
		tmp = (int *)malloc(count * sizeof(int));
		if (tmp == NULL)
			exit (1);
		array = ft_split(argv[i], ' ');
		ft_use_atoi(tmp, array, count);
		free(array);
		j = -1;
		while (count > ++j)
			created_list->stack_a[created_list->count + j] = tmp[j];
		created_list->count += count;
		free(tmp);
		i++;
	}
}
