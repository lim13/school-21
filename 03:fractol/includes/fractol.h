/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:57:13 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/07/04 17:57:14 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include <string.h>
# include <errno.h>
# include <stdlib.h>

# define BLACK 0x00000000
# define GREEN 0x10B9FEBA
# define YELLOW 0x00E2FB28
# define ESCAPE 53
# define ZOOM_PLUS 4
# define ZOOM_MINUS 5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	float	scale;
	char	**argv;

}				t_data;

typedef struct s_complex
{
	float	re;
	float	im;
}				t_complex;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ft_complex_sqr(t_complex *value);
t_complex	ft_complex_sum(t_complex value, t_complex value2);
float		ft_radius(t_complex value);
float		ft_complex_absolute(t_complex value);
void		fractol_julia(t_data	*img);
t_complex	complex_initialization(float re, float im);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fractol_mandelbrot(t_data	*img);
int			esc_close_the_win(int key, t_data *img);
int			mouse_zoom(int roll, int x, int y, t_data *img);

#endif
