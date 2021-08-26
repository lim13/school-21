/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:54:02 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/01 19:54:03 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_dot(const char *format, size_t *i, t_flags *flags, va_list
						arguments)
{
	(*i)++;
	if (format[(*i)] == '*')
	{
		flags->precision = va_arg(arguments, int);
		(*i)++;
	}
	else
	{
		flags->precision = 0;
		while (ft_is_digit(format[(*i)]) == 1)
		{
			flags->precision = flags->precision * 10 + format[(*i)] - '0';
			(*i)++;
		}
	}
}
