/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:12:50 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 12:12:53 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	process_char(char symb, t_flags flags)
{
	size_t	length;

	length = 0;
	if (flags.minus == 1)
		write(1, &symb, 1);
	length += ft_add_width(flags.width, 1, 0);
	if (flags.minus == 0)
		write (1, &symb, 1);
	length++;
	return (length);
}
