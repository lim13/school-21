/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:27:22 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/08 08:27:25 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_proc_prec_and_width(t_flags flags, char *string, size_t
										*length)
{
	if (flags.precision >= 0 && flags.precision < ft_strlen(string))
		flags.precision = ft_strlen(string);
	if (flags.precision >= 0)
	{
		flags.width = flags.width - flags.precision;
		*length += ft_add_width(flags.width, 0, 0);
	}
	else
		*length += ft_add_width(flags.width, ft_strlen(string), flags.zero);
}

static size_t	ft_string_count_and_malloc(char **string, unsigned long
											hex_long)
{
	size_t	counter;

	counter = 0;
	if (hex_long == 0)
	{
		(*string) = (char *)malloc(sizeof(char) * 2);
		if ((*string) == NULL)
			return (-1);
		(*string)[0] = '0';
		(*string)[1] = '\0';
	}
	if (hex_long != 0)
	{
		while (hex_long != 0)
		{
			hex_long = hex_long / 16;
			counter++;
		}
		*string = (char *) malloc(sizeof(char) * (counter + 1));
		if (*string == NULL)
			return (-1);
		(*string)[counter--] = '\0';
	}
	return (counter);
}

static	void	ft_hex_string_filling(unsigned long *hex_long, char **string,
										size_t *counter, int cap)
{
	if (cap == 0)
	{
		if (*hex_long % 16 < 10)
			(*string)[*counter] = *hex_long % 16 + 48;
		else
			(*string)[*counter] = *hex_long % 16 + 87;
	}
	if (cap == 1)
	{
		if (*hex_long % 16 < 10)
			(*string)[*counter] = *hex_long % 16 + 48;
		else
			(*string)[*counter] = *hex_long % 16 + 55;
	}
	*hex_long = *hex_long / 16;
	(*counter)--;
}

static	size_t	ft_proc_str_with_minus(char *string, t_flags *flags)
{
	size_t	length;

	length = 0;
	if (flags->precision >= 0)
	{
		length += ft_add_width(flags->precision, ft_strlen(string), 1);
		length += ft_proc_str_with_precision(string, ft_strlen(string));
	}
	else
		length += ft_proc_str_with_precision(string, ft_strlen(string));
	return (length);
}

size_t	process_hex(unsigned int hex, int cap, t_flags flags)
{
	char			*string;
	size_t			length;
	size_t			counter;
	unsigned long	hex_long;

	length = 0;
	hex = hex + 4294967295 + 1;
	hex_long = (unsigned long)hex;
	if (flags.precision == 0 && hex_long == 0)
		length += ft_add_width(flags.width, 0, 0);
	if (flags.precision == 0 && hex_long == 0)
		return (length);
	counter = ft_string_count_and_malloc(&string, hex_long);
	if (hex_long != 0)
		while (hex_long != 0 && (cap == 1 || cap == 0))
			ft_hex_string_filling(&hex_long, &string, &counter, cap);
	if (flags.minus == 1)
		length += ft_proc_str_with_minus(string, &flags);
	ft_proc_prec_and_width(flags, string, &length);
	if (flags.minus == 0)
		length += ft_proc_str_with_minus(string, &flags);
	free(string);
	return (length);
}
