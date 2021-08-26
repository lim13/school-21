/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:47:24 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/14 16:47:25 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s2 == NULL)
		return (0);
	ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	i = 0;
	if (tmp1 == 0 && tmp2 == 0)
		return (0);
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i = i + 1;
	}
	return ((void *)tmp1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) \
				* sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		new_str[j++] = s1[i++];
	while (s2[k] != '\0')
		new_str[i++] = s2[k++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	tmp;
	char	*tmp2;

	tmp = (char)c;
	tmp2 = (char *)s;
	if (*tmp2 == '\0' && tmp == '\0')
		return (tmp2);
	if (*tmp2 == '\0')
		return (0);
	while (*tmp2 != '\0')
	{
		if (*tmp2 == tmp)
			break ;
		tmp2++;
	}
	if (*tmp2 != tmp)
		return (NULL);
	return (tmp2);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
