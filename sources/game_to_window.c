/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:20 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 21:57:14 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	images(t_data *data)
{
	data->img_0 = mlx_xpm_file_to_image
		(data->mlx, "assets/images/back.xpm", &data->img_w, &data->img_h);
	data->img_1 = mlx_xpm_file_to_image
		(data->mlx, "assets/images/wall.xpm", &data->img_w, &data->img_h);
	data->img_p = mlx_xpm_file_to_image
		(data->mlx, "assets/images/pfr.xpm", &data->img_w, &data->img_h);
	data->img_e = mlx_xpm_file_to_image
		(data->mlx, "assets/images/exit.xpm", &data->img_w, &data->img_h);
	data->img_o = mlx_xpm_file_to_image
		(data->mlx, "assets/images/exit2.xpm", &data->img_w, &data->img_h);
	data->img_c = mlx_xpm_file_to_image
		(data->mlx, "assets/images/collect.xpm", &data->img_w, &data->img_h);
}

void	window_size(t_data *data)
{
	int	i;

	data->map_x = ft_strlen(data->map[0]);
	data->map_w = ft_strlen(data->map[0]) * 64;
	i = 0;
	while (data->map[i] != NULL)
		i++;
	data->map_h = i * 64;
	data->map_y = i;
}

void	game_to_window(t_data *data)
{
	data->mlx = mlx_init();
	window_size(data);
	data->win = mlx_new_window(data->mlx, data->map_w, data->map_h, "so_long");
	data->moves = 0;
	data->endgame = 0;
	images(data);
	map_draw(data);
}
