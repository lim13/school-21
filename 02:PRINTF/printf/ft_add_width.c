/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:56:44 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 15:56:46 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_add_width(int width, int printed_elements, int flag_null)
{
	size_t	length;

	length = 0;
	while (width - printed_elements > 0)
	{
		if (flag_null)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width--;
		length++;
	}
	return (length);
}
