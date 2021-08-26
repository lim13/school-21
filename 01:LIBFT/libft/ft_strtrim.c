/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:14:46 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/07 13:14:48 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_first_entr(char const c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

static char	*ft_defen(char const *s1, char const *set, char **new_str)
{
	if (s1 == NULL || set == NULL)
		return (0);
	if (s1[0] == '\0')
	{
		*new_str = (char *) malloc(1 * sizeof(char));
		if (*new_str == NULL)
			return (0);
		(*new_str)[0] = '\0';
	}
	return (*new_str);
}

static void	ft_check_count(char const *s1, char const *set, \
							size_t *count_start, size_t *count_end )
{
	size_t	i;

	i = 0;
	while (ft_first_entr(s1[i], set) != 0 && s1[i] != '\0')
		i++;
	*count_start = i;
	i = ft_strlen(s1) - 1;
	while (ft_first_entr(s1[i], set) != 0 && i >= 0)
		i--;
	*count_end = ft_strlen(s1) - i - 1;
}

static char	*ft_all_elem_in_set(char const *s1, size_t count_start, \
									size_t count_end, char **new_str)
{
	if (count_start == ft_strlen(s1) || count_end == ft_strlen(s1))
	{
		(*new_str) = (char *) malloc((1) * sizeof(char));
		if ((*new_str) == NULL)
			return (0);
		(*new_str)[0] = '\0';
	}
	return (*new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	count_start;
	size_t	count_end;

	count_end = 0;
	j = 0;
	if (s1 == NULL || set == NULL || s1[0] == '\0')
		return (ft_defen(s1, set, &new_str));
	ft_check_count(s1, set, &count_start, &count_end);
	if (count_start == ft_strlen(s1) || count_end == ft_strlen(s1))
		return (ft_all_elem_in_set(s1, count_start, count_end, &new_str));
	new_str = (char *) malloc((ft_strlen(s1) - count_start - count_end + 1) \
				* sizeof(char));
	if (new_str == NULL)
		return (0);
	i = 0;
	j = j + count_start;
	while (i < ft_strlen(s1) - count_start - count_end)
		new_str[i++] = s1[j++];
	new_str[i] = '\0';
	return (new_str);
}
