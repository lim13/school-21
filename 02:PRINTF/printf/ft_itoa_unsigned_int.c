/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:06:47 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/07 10:06:48 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_num_of_els(unsigned int *n, int *sign)
{
	long long	k;
	long long	f;

	f = *n;
	k = 0;
	if (*n < 0)
	{
		k = k + 1;
		*sign = -1;
		*n = (-1) * (*n);
	}
	else
		*sign = 1;
	while (f != 0)
	{
		f = f / 10;
		k = k + 1;
	}
	return (k);
}

static void	final_step(unsigned int n, char **str1, char **str2, int sign)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (sign < 0)
		(*str2)[j++] = '-';
	while (n != 0)
	{
		(*str1)[i++] = (n % 10) + '0';
		n = n / 10;
	}
	(*str1)[i--] = '\0';
	if (sign == -1)
		while (j < ft_strlen(*str1) + 1)
			(*str2)[j++] = (*str1)[i--];
	else
		while (j < ft_strlen(*str1))
			(*str2)[j++] = (*str1)[i--];
	(*str2)[j] = '\0';
}

char	*ft_itoa_unsigned_int(unsigned int n)
{
	char			*str1;
	char			*str2;
	unsigned int	i;
	int				sign;

	if (n == 0)
	{
		str2 = (char *)malloc(2 * sizeof(char));
		if (str2 == NULL)
			return (NULL);
		str2[0] = '0';
		str2[1] = '\0';
		return (str2);
	}
	i = n;
	str1 = (char *)malloc((ft_num_of_els(&n, &sign) + 1) * sizeof(char));
	if (str1 == NULL)
		return (NULL);
	str2 = (char *)malloc((ft_num_of_els(&i, &sign) + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	final_step(n, &str1, &str2, sign);
	free(str1);
	return (str2);
}
