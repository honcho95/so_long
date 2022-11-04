/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:10:37 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:21:39 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->num_collect = 0;
	data->num_player = 0;
	data->num_exit = 0;
	data->i = -1;
}

void	not_valid_path(t_data *d)
{
	ft_printf("Error\nThe path is not valid!");
	free_map(d->map);
	exit(1);
}
