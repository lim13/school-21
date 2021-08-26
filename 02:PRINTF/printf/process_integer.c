/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:00:24 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/05 15:00:25 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_proc_cut(t_flags *flags, char *string)
{
	size_t	length;

	length = 0;
	if (flags -> precision >= 0 && flags -> precision < ft_strlen(string))
		flags -> precision = ft_strlen(string);
	if (flags -> precision >= 0)
	{
		flags -> width = flags -> width - flags -> precision;
		length += ft_add_width(flags -> width, 0, 0);
	}
	else
		length += ft_add_width(flags -> width, ft_strlen(string), flags->zero);
	return (length);
}

static	size_t	ft_proc_int_with_flag_minus(int buffer, t_flags *flags, char
											*string, int num)
{
	size_t	length;

	length = 0;
	if (buffer < 0 && flags -> precision >= 0 && num > -2147483648)
		write(1, "-", 1);
	if (flags->precision >= 0)
		length += ft_add_width(flags -> precision - 1, ft_strlen(string) - 1,
				1);
	length += ft_proc_str_with_precision(string, ft_strlen(string));
	return (length);
}

static	size_t	ft_negat_num(t_flags *flags, int *num)
{
	size_t	length;

	length = 0;
	if (flags -> zero == 1 && flags -> precision < 0 && *num > -2147483648)
		write(1, "-", 1);
	if (*num == -2147483648)
		length--;
	*num = *num * (-1);
	flags -> zero = 1;
	flags -> width = flags -> width - 1;
	length++;
	return (length);
}

size_t	process_integer(int num, t_flags flags)
{
	char	*string;
	int		buffer;
	size_t	length;

	buffer = num;
	length = 0;
	if (flags.precision == 0 && num == 0)
		length += ft_add_width(flags.width, 0, 0);
	else
	{
		if (num < 0 && (flags.precision >= 0 || flags.zero == 1))
			length += ft_negat_num(&flags, &num);
		string = ft_itoa(num);
		if (flags.minus == 1)
			length += ft_proc_int_with_flag_minus(buffer, &flags, string, num);
		length += ft_proc_cut(&flags, string);
		if (flags.minus == 0)
			length += ft_proc_int_with_flag_minus(buffer, &flags, string, num);
		free(string);
	}
	return (length);
}
