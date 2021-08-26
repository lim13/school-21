/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:08:49 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/04 21:08:51 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*ft_conditions(char const *s, unsigned int start, size_t
										len, unsigned char *result)
{
	if (start + len > ft_strlen(s) && start < ft_strlen(s))
	{
		result = (unsigned char *)malloc((ft_strlen(s) - start + 1) * sizeof
				(char));
		if (result == NULL)
			return (NULL);
	}
	else if (start >= ft_strlen(s))
	{
		result = (unsigned char *)malloc((1) * sizeof (char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	else
	{
		result = (unsigned char *) malloc((len + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
	}
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*result;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	result = 0;
	result = ft_conditions(s, start, len, result);
	if (result == NULL || start >= ft_strlen(s))
		return ((char *)result);
	while (s[i] != '\0')
	{
		if (i == start)
		{
			while (j < len && s[i] != '\0')
				result[j++] = s[i++];
			result[j] = '\0';
			return ((char *)result);
		}
		i++;
	}
	return (NULL);
}
