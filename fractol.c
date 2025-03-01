/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:25 by ylabser           #+#    #+#             */
/*   Updated: 2025/03/01 15:37:26 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void *value)
{
	if (!value)
		exit(1);
}

static void	data_init(t_data *data)
{
	data->color = 0x00050707;
	data->iterations = 100;
	data->zoom = 1.0;
	data->mlx = mlx_init();
	ft_error(data->mlx);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_error(data->win);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_error(data->img);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->size_line,
			&data->endian);
	ft_error(data->addr);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, CLOSE_BUTTON, 0, close_window, data);
}

static void	display_usage(void)
{
	ft_write("Usage:\n");
	ft_write("./fractol mandelbrot\n");
	ft_write("./fractol julia 0.45 0.6\n");
	ft_write("Controls:\n");
	ft_write("mouse wheel zoom\n");
	ft_write("+/- add/reduce detail\n");
	ft_write("b key reset\n");
}

static void	handle_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		data->name = "mandelbrot";
		return ;
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia")
		&& valid_value(argv[2])
		&& valid_value(argv[3]))
	{
		data->name = "julia";
		data->c.real = ft_atodouble(argv[2]);
		data->c.imaginary = -ft_atodouble(argv[3]);
		return ;
	}
	display_usage();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data);
	data_init(&data);
	render(data);
	mlx_loop(data.mlx);
}
