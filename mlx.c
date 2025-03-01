/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:39 by ylabser           #+#    #+#             */
/*   Updated: 2025/03/01 15:37:40 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(t_data data, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	offset = y * data.size_line + x * (data.bits_per_pixel / 8);
	*(int *)(data.addr + offset) = color;
}

double	scale(double value, double min, double max, double dimension)
{
	return ((value / dimension) * (max - min) + min);
}

static int	get_color(int x, int y, t_data data)
{
	int			i;
	t_complex	point;

	point.real = scale(x, -2, 2, WIDTH) * data.zoom;
	point.imaginary = scale(y, -2, 2, HEIGHT) * data.zoom;
	if (!ft_strcmp(data.name, "mandelbrot"))
		data.c = point;
	else if (!ft_strcmp(data.name, "julia"))
		data.z = point;
	i = 0;
	while (i < data.iterations)
	{
		data.z = sum(square(data.z), data.c);
		if (magnitude(data.z) > 2)
			return (i * data.color);
		i++;
	}
	return (0);
}

void	render(t_data data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_color(x, y, data);
			pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
}
