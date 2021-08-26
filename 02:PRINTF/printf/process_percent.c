/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:17:25 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 12:17:27 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	process_percent(t_flags flags)
{
	size_t	length;

	length = 0;
	if (flags.minus == 1)
	{
		write(1, "%", 1);
		length += ft_add_width(flags.width, 1, 0);
	}
	if (flags.minus == 0)
	{
		length += ft_add_width(flags.width, 1, flags.zero);
		write(1, "%", 1);
	}
	return (length + 1);
}
