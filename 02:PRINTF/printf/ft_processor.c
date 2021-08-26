/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:37:17 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/05 15:00:10 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_processor(char type, t_flags *flags, va_list arguments)
{
	size_t	length;

	length = 0;
	if (type == 'c')
		length = process_char(va_arg(arguments, int), *flags);
	else if (type == 's')
		length = process_string(va_arg(arguments, char *), *flags);
	else if (type == 'p')
		length = process_pointer(va_arg(arguments, unsigned long), flags);
	else if (type == 'd' || type == 'i')
		length = process_integer(va_arg(arguments, int), *flags);
	else if (type == 'u')
		length = process_unsigned_int(va_arg(arguments, unsigned int),
				*flags);
	else if (type == 'x')
		length = process_hex(va_arg(arguments, unsigned int),
				0, *flags);
	else if (type == 'X')
		length = process_hex(va_arg(arguments, unsigned int),
				1, *flags);
	else if (type == '%')
		length = process_percent(*flags);
	return (length);
}
