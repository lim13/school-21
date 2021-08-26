/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:17:45 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 12:17:46 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	process_string(char *string, t_flags flags)
{
	size_t	length;

	length = 0;
	if (string == NULL)
		string = "(null)";
	if (flags.precision > ft_strlen(string))
		flags.precision = ft_strlen(string);
	if (flags.minus == 1)
		length = ft_proc_minus(string, flags);
	if (flags.precision >= 0)
		length += ft_add_width(flags.width, flags.precision, flags.zero);
	else
		length += ft_add_width(flags.width, ft_strlen(string), flags.zero);
	if (flags.minus == 0)
		length += ft_proc_minus(string, flags);
	return (length);
}
