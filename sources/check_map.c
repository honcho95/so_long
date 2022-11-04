/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:44:59 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 22:22:00 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rect(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_pec(t_data *data)
{
	init_data(data);
	while (data->map[++data->i] != NULL)
	{
		data->j = -1;
		while (data->map[data->i][++data->j] != '\0')
		{
			if (data->map[data->i][data->j] == 'P')
			{
				data->start_px = data->j;
				data->start_py = data->i;
				data->num_player++;
			}
			else if (data->map[data->i][data->j] == 'E')
			{
				data->exit_x = data->j;
				data->exit_y = data->i;
				data->num_exit++;
			}
			else if (data->map[data->i][data->j] == 'C')
				data->num_collect++;
		}
	}
	if (data->num_player != 1 || data->num_exit != 1 || data->num_collect == 0)
		return (0);
	return (1);
}

static int	is_playable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_data *d)
{
	if (is_rect(d->map) && is_wall(d->map) && is_pec(d)
		&& is_playable(d->map))
	{
		window_size(d);
		if ((check_path(d, d->start_px, d->start_py)) == 0)
			not_valid_path(d);
		free_map(d->map);
		return (1);
	}
	return (0);
}
