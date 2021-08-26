/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:49:38 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/04/29 16:49:41 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
