/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:23:44 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/01 13:23:48 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_initialization(float re, float im)
{
	t_complex	complex_number;

	complex_number.re = re;
	complex_number.im = im;
	return (complex_number);
}

float	ft_complex_absolute(t_complex value)
{
	float	abs;

	abs = sqrtf(value.im * value.im + value.re * value.re);
	return (abs);
}

float	ft_radius(t_complex value)
{
	float	radius;

	radius = 1 + sqrtf(1 + 4 * (ft_complex_absolute(value)));
	return (radius);
}

t_complex	ft_complex_sum(t_complex value1, t_complex value2)
{
	t_complex	complex_sum;

	complex_sum.re = value1.re + value2.re;
	complex_sum.im = value1.im + value2.im;
	return (complex_sum);
}

void	ft_complex_sqr(t_complex *value)
{
	t_complex	complex_sqr;

	complex_sqr = *value;
	value->re = (complex_sqr.re * complex_sqr.re) - (
			complex_sqr.im * complex_sqr.im);
	value->im = 2 * complex_sqr.re * complex_sqr.im;
}
