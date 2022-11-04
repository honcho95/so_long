/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:45:30 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:23:21 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_endl(char *str)
{
	int	i;
	int	check1;
	int	check2;

	i = 0;
	check1 = 0;
	check2 = 0;
	while (str[i])
	{
		if (str[i] == '1')
			check1 = 1;
		if (str[i] == '\n' && str[i + 1] != '1' && check1 == 1)
			check2 = 1;
		if (str[i] == '1' && check2 == 1)
		{
			ft_printf("Error\nMap is invalid!");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**read_map(char *path)
{
	t_par	par;

	par.fd = open(path, O_RDONLY);
	if (par.fd == -1)
		return (NULL);
	par.holder1 = ft_strdup("");
	while (1)
	{
		par.line = get_next_line(par.fd);
		if (!par.line)
			break ;
		par.holder2 = par.holder1;
		par.holder1 = ft_strjoin(par.holder2, par.line);
		free(par.line);
		free(par.holder2);
	}
	if (check_endl(par.holder1) == 0)
	{
		free(par.holder1);
		exit(0);
	}
	par.map = ft_split(par.holder1, '\n');
	free(par.holder1);
	close(par.fd);
	return (par.map);
}
