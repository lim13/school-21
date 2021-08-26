/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:17:55 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 12:17:57 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_proc_cut(t_flags *flags, char *string, size_t *length)
{
	if (flags -> precision >= 0 && flags -> precision <= ft_strlen(string))
		flags -> precision = ft_strlen(string);
	if (flags -> precision >= 0)
	{
		flags -> width = flags -> width - flags -> precision;
		(*length) += ft_add_width(flags -> width, 0, 0);
	}
	else
		(*length) += ft_add_width(flags -> width, ft_strlen(string),
				  flags->zero);
}

static size_t	ft_process_minus(t_flags flags, char *string)
{
	size_t	length;

	length = 0;
	if (flags.precision >= 0)
		length += ft_add_width(flags.precision, ft_strlen(string), 1);
	length += ft_proc_str_with_precision(string, ft_strlen(string));
	return (length);
}

size_t	process_unsigned_int(unsigned int num, t_flags flags)
{
	char	*string;
	size_t	length;

	length = 0;
	num = num + 4294967295 + 1;
	if (flags.precision == 0 && num == 0)
		length += ft_add_width(flags.width, 0, 0);
	else
	{
		string = ft_itoa_unsigned_int(num);
		if (flags.minus == 1)
			length += ft_process_minus(flags, string);
		ft_proc_cut(&flags, string, &length);
		if (flags.minus == 0)
			length += ft_process_minus(flags, string);
		free(string);
	}
	return (length);
}
