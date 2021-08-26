/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_str_with_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:23:29 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/04 15:23:32 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_proc_str_with_precision(char *string, int precision)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0' && (int)length < precision)
	{
		write (1, &string[length], 1);
		length++;
	}
	return (length);
}
