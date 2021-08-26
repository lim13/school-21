/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:17:36 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/06/03 12:17:37 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string_filling(unsigned long *pointer, char **string, size_t
								*counter)
{
	while (*pointer != 0)
	{
		if ((*pointer % 16) < 10)
			(*string)[*counter] = (*pointer % 16) + 48;
		else
			(*string)[*counter] = (*pointer % 16) + 87;
		*pointer = *pointer / 16;
		(*counter)--;
	}
}

static size_t	ft_while_pointer(unsigned long pointer)
{
	size_t	counter;

	counter = 0;
	while (pointer != 0)
	{
		pointer = pointer / 16;
		counter++;
	}
	return (counter);
}

static int	ft_malloc_and_filling(unsigned long pointer, char **string)
{
	size_t			counter;

	counter = 0;
	if (pointer == 0)
	{
		*string = (char *)malloc(sizeof(char) * 4);
		if (*string == NULL)
			return (-1);
		(*string)[0] = '0';
		(*string)[1] = '\0';
	}
	else
	{
		counter = ft_while_pointer(pointer);
		*string = (char *) malloc(sizeof(char) * (counter + 1));
		if (*string == NULL)
			return (-1);
		(*string)[counter--] = '\0';
		ft_string_filling(&pointer, string, &counter);
	}
	return (1);
}

static	size_t	ft_proc_str_with_minus(char *string, t_flags *flags)
{
	size_t	length;

	length = 0;
	length += ft_proc_str_with_precision("0x", 2);
	if (flags -> precision >= 0)
	{
		length += ft_add_width(flags -> precision - 1, ft_strlen(string), 0);
		length += ft_proc_str_with_precision(string, flags -> precision);
	}
	else
		length += ft_proc_str_with_precision(string, ft_strlen(string));
	return (length);
}

size_t	process_pointer(unsigned long pointer, t_flags *flags)
{
	char			*string;
	size_t			length;

	length = 0;
	if (pointer == 0 && flags -> precision == 0)
	{
		length += ft_proc_str_with_precision("0x", 2);
		length += ft_add_width(flags -> width, 0, 1);
		return (length);
	}
	if (ft_malloc_and_filling(pointer, &string) == -1)
		return (-1);
	if (flags -> minus == 1)
		length += ft_proc_str_with_minus(string, flags);
	length += ft_add_width(flags -> width, ft_strlen(string) + 2, 0);
	if (flags -> minus == 0)
		length += ft_proc_str_with_minus(string, flags);
	free(string);
	return (length);
}
