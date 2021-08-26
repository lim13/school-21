/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:11:38 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/01 12:11:41 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse_flag(const char *format, size_t i, t_flags *flags, va_list
						arguments)
{
	while (format[i] != '\0')
	{
		if (format[i] == '0' && ((flags->width) == 0) && \
			((flags->minus) != '-'))
			flags->zero = 1;
		if (format[i] == '.')
			ft_flag_dot(format, &i, flags, arguments);
		if (format[i] == '*')
			ft_flag_width(flags, arguments);
		if (format[i] == '-')
			ft_flag_minus(flags);
		if (ft_is_digit(format[i]) == 1)
			ft_flag_digit(flags, format[i]);
		if (ft_is_type(format[i]) == 1)
		{
			flags->type = (unsigned char) format[i];
			break ;
		}
		i++;
	}
	return (i);
}
