/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:08:15 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/27 13:08:17 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t		length;
	va_list		arguments;

	length = 0;
	va_start(arguments, format);
	length = ft_parse_input(arguments, format);
	va_end(arguments);
	return ((int)length);
}
