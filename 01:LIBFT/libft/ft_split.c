/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:18:03 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/07 20:18:05 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_num_of_words(char const *s, char c, size_t *j)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			(*j)++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (*j);
}

static size_t	ft_malloc_words(char c, char const *s, size_t *i)
{
	size_t	k;

	k = 0;
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	while (s[*i] != c && s[*i] != '\0')
	{
		(*i)++;
		k++;
	}
	return (k);
}

static char	**ft_arr_filling(char ***array, size_t *j, char c, char const *s)
{
	size_t	p;
	size_t	i;
	size_t	k;

	i = 0;
	p = *j;
	*j = 0;
	while (*j < p)
	{
		k = ft_malloc_words(c, s, &i);
		(*array)[*j] = (char *)malloc((k + 1) * sizeof(char));
		if ((*array)[*j] == NULL)
		{
			while (*j-- >= 0)
				free((*array)[*j]);
			free(*array);
			return (0);
		}
		i = i - k;
		k = 0;
		while (s[i] != c && s[i] != '\0')
			(*array)[*j][k++] = s[i++];
		(*array)[(*j)++][k] = '\0';
	}
	return (*array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	ft_num_of_words(s, c, &j);
	array = (char **)malloc((j + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (j == 0)
	{
		array[0] = NULL;
		return (array);
	}
	ft_arr_filling(&array, &j, c, s);
	array[j] = NULL;
	return (array);
}
