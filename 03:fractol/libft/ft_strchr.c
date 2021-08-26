/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:00:41 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/03 17:00:43 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
