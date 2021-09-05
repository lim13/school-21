/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:45:40 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/09/04 18:45:41 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_correct_str(char *argv)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 0;
    num = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] >= 48 && argv[i] <= 57)
            num++;
        else if ((argv[i] == 43 || argv[i] == 45) && (argv[i] != '\0') && sign == 0 && num == 0)
            sign++;
        else if (argv[i] == '\t' || argv[i] == ' ')
        {
            if (num == 0 && sign != 0)
            {
                write (1, "Error\n", 6);
                exit(1);
            }
            num = 0;
            sign = 0;
        }
        else
        {
            write (1, "Error\n", 6);
            exit(1);
        }
        i++;
    }
}

static int ft_numbers_presense(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] >= 48 && argv[i] <= 57)
            return (1);
        i++;
    }
    return (0);
}

static int ft_check_separators(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] == '\n' || argv[i] == '\f' || argv[i] == '\t' ||
            argv[i] == '\v' || argv[i] == ' ' || argv[i] == '\r')
            i++;
        else
            return (1);
    }
    return (0);
}

int ft_check_data(int argc, char **argv)
{
	int i;
    int checker;

    checker = 0;
	i = 1;
	while (i < argc)
	{
	    if (ft_check_separators(argv[i]) == 1)
	    {
            if (ft_numbers_presense(argv[i]) == 0)
            {
                write (1, "Error\n", 6);
                exit(1);
            }
            ft_correct_str(argv[i]);
            checker = 1;
	    }
	    i++;
	}
	return (checker);
}
