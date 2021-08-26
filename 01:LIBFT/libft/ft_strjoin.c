/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:19:23 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/05 15:19:25 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
