/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:46:23 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 22:31:42 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	int		a;
	int		b;
	int		i;
	int		j;
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_e;
	void	*img_o;
	void	*img_c;
	int		map_w;
	int		map_h;
	int		map_x;
	int		map_y;
	int		img_w;
	int		img_h;
	int		num_collect;
	int		num_player;
	int		num_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	int		start_px;
	int		start_py;
	int		exit_x;
	int		exit_y;
}	t_data;

typedef struct s_par
{
	int		fd;
	char	*line;
	char	*holder1;
	char	*holder2;
	char	**map;
}	t_par;

# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

void	img_draw(t_data *data, void *image, int x, int y);
int		map_draw(t_data *data);
void	game_to_window(t_data *data);
void	window_size(t_data *data);
char	**read_map(char *path);
int		check_map(t_data *data);
void	gameplay(t_data *data);
void	player_w(t_data *data);
void	player_d(t_data *data);
void	player_s(t_data *data);
void	player_a(t_data *data);
int		exit_game(t_data *data);
void	free_map(char **map);
void	init_data(t_data *data);
int		check_path(t_data *data, int x, int y);
void	not_valid_path(t_data *d);

#endif
