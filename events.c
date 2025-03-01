/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:37:17 by ylabser           #+#    #+#             */
/*   Updated: 2025/03/01 15:37:19 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == B_KEY)
		data->zoom = 1;
	else if (keycode == PLUS_KEY)
		data->iterations += 10;
	else if (keycode == MINUS_KEY)
		data->iterations -= 10;
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		data->zoom *= 1.10;
	else if (button == SCROLL_DOWN)
		data->zoom *= 0.90;
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}
