/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:36:28 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/05 17:36:31 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_extra_opt(int n)
{
	int		j;
	char	*s;
	char	*str2;

	s = "-2147483648";
	if (n == -2147483648)
	{
		str2 = (char *)malloc(12 * sizeof(char));
		if (str2 == NULL)
			return (NULL);
		j = -1;
		while (++j < ft_strlen(s))
			str2[j] = s[j];
		str2[j] = '\0';
	}
	if (n == 0)
	{
		str2 = (char *)malloc(2 * sizeof(char));
		if (str2 == NULL)
			return (NULL);
		str2[0] = '0';
		str2[1] = '\0';
	}
	return (str2);
}

static int	ft_num_of_els(int *n, int *sign)
{
	int	k;
	int	f;

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

static void	final_step(int n, char **str1, char **str2, int sign)
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

char	*ft_itoa(int n)
{
	char	*str1;
	char	*str2;
	int		i;
	int		sign;

	if (n == -2147483648 || n == 0)
		return (ft_extra_opt(n));
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
