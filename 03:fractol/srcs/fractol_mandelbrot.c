/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:56:04 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/01 12:56:07 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_values
{
	t_complex	c;
	t_complex	z;
	int			x;
	int			y;
	int			num_of_iter;
}				t_values;

static int	fractol_ft_mandelbrot(t_complex z, t_complex c, float r, int
max_num_of_iter)
{
	int	n;

	n = -1;
	while (++n < max_num_of_iter)
	{
		ft_complex_sqr(&z);
		z = ft_complex_sum(z, c);
		if (ft_complex_absolute(z) > r)
			break ;
	}
	return (n);
}

void	fractol_mandelbrot(t_data	*img)
{
	t_values	v;
	int			max_num_of_iter;
	float		r;

	max_num_of_iter = 20;
	v.x = -1;
	while (++v.x < img->width)
	{
		v.y = -1;
		while (++v.y < img->height)
		{
			v.z = complex_initialization(0, 0);
			v.c = complex_initialization(((float)v.x - (float)(img->width / 2)
						) / ((float)img->width / (2 * r) * img->scale), ((float)
						(img->height / 2) - (float)v.y) / ((float)img->height
						/ (2 * r) * img->scale));
			r = ft_radius(v.c);
			v.num_of_iter = fractol_ft_mandelbrot(v.z, v.c, r, max_num_of_iter);
			if (v.num_of_iter != max_num_of_iter)
				my_mlx_pixel_put(img, v.x, v.y, GREEN + (float)v.num_of_iter / (
						float)(max_num_of_iter - 1) *(YELLOW - GREEN));
			else
				my_mlx_pixel_put(img, v.x, v.y, BLACK);
		}
	}
}
