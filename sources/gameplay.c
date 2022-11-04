/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:22 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:06:50 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		data->y_player -= 1;
		player_w(data);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		data->y_player += 1;
		player_s(data);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->x_player += 1;
		player_d(data);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		data->x_player -= 1;
		player_a(data);
	}
}

static int	keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_game(data);
	else if (!data->endgame)
		game_events(keycode, data);
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, keypress, data);
	mlx_hook(data->win, 17, 1L << 17, exit_game, data);
}
