/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:01:26 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 20:27:15 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../minilibx_opengl/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	void		*img_bckgnd;
	void		*img_wall;
	void		*img_player;
	void		*img_collect;
	void		*img_exit;
	int			map_w;
	int			map_h;
	int			img_w;
	int			img_h;
	int			n_collect;
	int			n_player;
	int			n_exit;
	int			player_x;
	int			player_y;
	int			moves_count;
	int			end_game;
}	t_game;

# define KEY_A	0
# define KEY_W	13
# define KEY_S	1
# define KEY_D	2

# define KEY_Q	12
# define KEY_ESQ	53

void	render_img(t_game *game, void *img, int x, int y);
int		render_map(t_game *game);
void	start_game(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	release_memory(char **map);
int		exit_game(t_game *game);
void	sprite_animation(char instruction, t_game *game);

#endif
