/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 18:27:26 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/04/30 18:27:30 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	i = 0;
	if (tmp1 > tmp2)
	{
		tmp2 = tmp2 + (len - 1);
		tmp1 = tmp1 + (len - 1);
		while (len--)
			*tmp1-- = *tmp2--;
		tmp1 = tmp1 + 1;
	}
	else if (tmp1 < tmp2)
	{
		while (i < len)
		{
			tmp1[i] = tmp2[i];
			i = i + 1;
		}
	}
	return ((void *)tmp1);
}
