/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:55:54 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/01 13:55:56 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int roll, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (roll == ZOOM_PLUS)
		img->scale *= 2;
	else if (roll == ZOOM_MINUS)
		img->scale /= 2;
	if (ft_strncmp(img->argv[1], "Julia", 6) == 0)
		fractol_julia(img);
	else if (ft_strncmp(img->argv[1], "Mandelbrot", 11) == 0)
		fractol_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}
