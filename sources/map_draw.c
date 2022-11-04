/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:24 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 22:29:14 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_data *data, void *image, int x, int y)
{
	mlx_put_image_to_window
		(data->mlx, data->win, image, x * 64, y * 64);
}

static void	player_draw(t_data *data, void *image, int x, int y)
{
	data->x_player = x;
	data->y_player = y;
	img_draw(data, image, x, y);
}

static void	exit_draw(t_data *data, int x, int y)
{
	if (data->num_collect == 0)
	{
		img_draw(data, data->img_o, x, y);
	}
	else
		img_draw(data, data->img_e, x, y);
}

void	count_moves(t_data *data)
{
	char	*str;

	str = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->win, 25, 25, 0xFFFF00, "MOVES:");
	mlx_string_put(data->mlx, data->win, 65, 25, 0xFEFEFE, str);
	free(str);
}

int	map_draw(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				img_draw(data, data->img_1, x, y);
			else if (data->map[y][x] == '0')
				img_draw(data, data->img_0, x, y);
			else if (data->map[y][x] == 'P')
				player_draw(data, data->img_p, x, y);
			else if (data->map[y][x] == 'C')
				img_draw(data, data->img_c, x, y);
			else if (data->map[y][x] == 'E')
				exit_draw(data, x, y);
			x++;
		}
		y++;
		count_moves(data);
	}
	return (0);
}
