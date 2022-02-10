/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:51:29 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 07:59:52 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/includes/ft_printf.h"

/* INFO: bckgnd = background | w = width | h = height */

typedef struct	s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_images
{
	void	*img_bckgnd;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_images;


typedef	struct	s_game
{
	void	*mlx;
	void	*win;
	void	**map;
	t_images	*img_hooks;
	int	map_w;
	int	map_h;
	int	img_w;
	int	img_h;
	int	n_collect;
	int	n_player;
	int	n_exit;
	t_coords	*player_c;
	int	moves_count;
	int	end_game;
}	t_game;

# define Key_A	97
# define Key_W	119
# define Key_S	115
# define Key_D	100

# define Key_Arrow_Left	65361
# define Key_Arrow_Up	65362
# define Key_Arrow_Down	65364
# define Key_Arrow_Right	65363

# define Key_ESQ	65307


void	render_img(t_game *game, void *img, int x, int y);
int	render_map(t_game *game);
void	start_game(t_game *game);
char	**read_map(char *path);
int	map_checker(t_game *game);
void	gameplay(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	release_memory(char **map);
int	exit_game(t_game *game);

#endif
