/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:03:44 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 22:31:03 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_exit(char **map, t_data *data, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'Y')
		return (0);
	if (map[y][x] == 'C')
		data->num_collect --;
	else if (map[y][x] == 'E')
		data->num_exit --;
	map[y][x] = 'Y';
	if (x + 1 < data->map_x)
		find_exit(map, data, x + 1, y);
	if (x - 1 > 0)
		find_exit(map, data, x - 1, y);
	if (y - 1 > 0)
		find_exit(map, data, x, y - 1);
	if (y + 1 < data->map_y)
		find_exit(map, data, x, y + 1);
	return (0);
}

int	check_path(t_data *data, int x, int y)
{
	int	collect;
	int	exit;
	int	ret;

	ret = 1;
	collect = data->num_collect;
	exit = data->num_exit;
	find_exit(data->map, data, x, y);
	if (data->num_collect > 0 || data->num_exit > 0)
		ret = 0;
	data->num_collect = collect;
	data->num_exit = exit;
	return (ret);
}
