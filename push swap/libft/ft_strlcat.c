/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:45:28 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/02 16:45:30 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, \
					size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	ret;

	i = 0;
	k = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	if (src[0] == '\0')
		return (ft_strlen(src) + ft_strlen(dst));
	i = ft_strlen(dst);
	ret = ft_strlen(src) + ft_strlen(dst);
	while ((dstsize - i - 1) > 0)
	{
		if (src[k] == '\0')
			break ;
		dst[i] = src[k];
		k++;
		i++;
	}
	dst[i] = '\0';
	return (ret);
}
