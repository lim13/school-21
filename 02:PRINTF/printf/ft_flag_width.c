/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:25 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/02 14:24:27 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width(t_flags *flags, va_list arguments)
{
	flags->star = 1;
	flags->width = va_arg(arguments, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = flags->width * (-1);
		flags->zero = 0;
	}
}
