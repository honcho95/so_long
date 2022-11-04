/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:31 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 22:14:00 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
		&& av [i - 3] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		data.map = read_map(av[1]);
		if (check_map(&data) && check_ber(av[1]))
		{
			data.map = read_map(av[1]);
			game_to_window(&data);
			gameplay(&data);
			mlx_loop(data.mlx);
		}
		else
		{
			if (data.map)
				free_map(data.map);
			ft_printf("Error\nInvalid map!");
			exit(1);
		}
	}
	ft_printf("Error\nOnly two arguments allowed!");
	return (0);
}
