/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:03:21 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/31 18:03:23 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_write_text_symbols_after_percent(const char *format,
													size_t *i,	size_t *length)
{
	write(1, &format[(*i)], 1);
	(*length)++;
}

static	void	ft_write_text_symbols_before_percent(const char *format,
													 size_t *i,	size_t *length)
{
	write(1, &format[(*i)], 1);
	(*i)++;
	(*length)++;
}

static	void	ft_proc_space(const char *format, size_t *i, size_t *length)
{
	if (format[*i + 1] == ' ')
	{
		write(1, " ", 1);
		(*length)++;
		(*i)++;
	}
	(*i)++;
}

size_t	ft_parse_input(va_list arguments, const char *format)
{
	size_t	i;
	size_t	length;
	t_flags	flags;

	i = 0;
	length = 0;
	while (1)
	{
		ft_init_flags(&flags);
		if (format[i] == '\0')
			break ;
		if (format[i] == '%')
		{
			ft_proc_space(format, &i, &length);
			i = ft_parse_flag(format, i, &flags, arguments);
			if (ft_is_type(format[i]) == 1)
				length += ft_processor(format[i], &flags, arguments);
			else
				ft_write_text_symbols_after_percent(format, &i, &length);
			i++;
		}
		else
			ft_write_text_symbols_before_percent(format, &i, &length);
	}
	return (length);
}
