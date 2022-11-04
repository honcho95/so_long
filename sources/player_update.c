/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:26 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:21:56 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update_image(char key, t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_p);
	if (key == 'w')
		data->img_p = mlx_xpm_file_to_image
			(data->mlx, "assets/images/pfr.xpm", &data->img_w, &data->img_h);
	else if (key == 's')
		data->img_p = mlx_xpm_file_to_image
			(data->mlx, "assets/images/pfl.xpm", &data->img_w, &data->img_h);
	else if (key == 'd')
		data->img_p = mlx_xpm_file_to_image
			(data->mlx, "assets/images/pfr.xpm", &data->img_w, &data->img_h);
	else if (key == 'a')
		data->img_p = mlx_xpm_file_to_image
			(data->mlx, "assets/images/pfl.xpm", &data->img_w, &data->img_h);
}

void	player_w(t_data *data)
{
	player_update_image('w', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->num_collect == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_printf("Congrats, you won!");
		data->map[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
		exit_game(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->y_player += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->map[data->y_player][data->x_player] == 'C')
			data->num_collect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_s(t_data *data)
{
	player_update_image('s', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->num_collect == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_printf("Congrats, you won!");
		data->map[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
		exit_game(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->y_player -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->map[data->y_player][data->x_player] == 'C')
			data->num_collect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_d(t_data *data)
{
	player_update_image('d', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->num_collect == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_printf("Congrats, you won!");
		data->map[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
		exit_game(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->x_player -= 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->map[data->y_player][data->x_player] == 'C')
			data->num_collect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		map_draw(data);
	}
}

void	player_a(t_data *data)
{
	player_update_image('a', data);
	if (data->map[data->y_player][data->x_player] == 'E'
			&& data->num_collect == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		ft_printf("Congrats, you won!");
		data->map[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		data->endgame = 1;
		map_draw(data);
		exit_game(data);
	}
	else if (data->map[data->y_player][data->x_player] == '1'
			|| data->map[data->y_player][data->x_player] == 'E')
		data->x_player += 1;
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->map[data->y_player][data->x_player] == 'C')
			data->num_collect -= 1;
		data->map[data->y_player][data->x_player] = 'P';
		data->map[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		map_draw(data);
	}
}
