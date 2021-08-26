/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:34:44 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/07/04 16:34:45 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	values(t_data *img, char **argv)
{
	img->argv = argv;
	img->height = 800;
	img->width = 800;
	img->scale = 1;
}

int	main(int argc, char **argv)
{
	t_data	img;

	values(&img, argv);
	if (argc != 2)
		return (0);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "FRACTOL");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img
			.line_length, &img.endian);
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
		fractol_julia(&img);
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		fractol_mandelbrot(&img);
	else
	{
		printf("Julia , Mandelbrot\n");
		return (0);
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 0, esc_close_the_win, &img);
	mlx_mouse_hook(img.mlx_win, mouse_zoom, &img);
	mlx_do_sync(img.mlx);
	mlx_loop(img.mlx);
	return (0);
}
