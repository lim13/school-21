/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:35:17 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/04/29 18:35:19 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, \
						int c, size_t n)
{
	size_t			i;
	unsigned char	marker;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	marker = c;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == marker)
		{
			i = i + 1;
			return ((void *)tmp1 + i);
		}
		i = i + 1;
	}
	return (0);
}
