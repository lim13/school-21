/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:20:05 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/05 14:20:07 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_proc_minus(char	*string, t_flags flags)
{
	size_t	length;

	length = 0;
	if (flags.precision >= 0)
		length += ft_proc_str_with_precision(string, flags.precision);
	else
		length += ft_proc_str_with_precision(string, ft_strlen(string));
	return (length);
}
