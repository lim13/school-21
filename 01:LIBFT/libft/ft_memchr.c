/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:44:01 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/01 12:44:03 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*tmp;
	size_t			i;

	a = (unsigned char)c;
	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == a)
			return ((void *)&tmp[i]);
		i = i + 1;
	}
	return (NULL);
}
