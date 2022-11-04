/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:16 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:55:44 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_data *data)
{
	free_map(data->map);
	mlx_destroy_image(data->mlx, data->img_0);
	mlx_destroy_image(data->mlx, data->img_1);
	mlx_destroy_image(data->mlx, data->img_p);
	mlx_destroy_image(data->mlx, data->img_e);
	mlx_destroy_image(data->mlx, data->img_o);
	mlx_destroy_image(data->mlx, data->img_c);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
