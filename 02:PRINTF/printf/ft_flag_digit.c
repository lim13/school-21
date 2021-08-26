/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:59:02 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/02 15:59:03 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_digit(t_flags *flags, char dig)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = flags->width * 10 + (dig - '0');
}
