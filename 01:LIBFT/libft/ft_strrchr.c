/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:22:39 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/03 18:22:41 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tmp;
	char	*tmp2;
	int		i;

	i = ft_strlen(s);
	tmp = (char)c;
	tmp2 = (char *)s;
	if (*tmp2 == '\0' && c != '\0')
		return (NULL);
	tmp2 = tmp2 + ft_strlen(s);
	while (i >= 0)
	{
		if (*tmp2 == tmp)
			break ;
		tmp2--;
		i--;
	}
	if (*tmp2 != tmp)
		return (NULL);
	return (tmp2);
}
