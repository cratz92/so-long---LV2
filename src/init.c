/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:07:04 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/12 20:31:06 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* images size of (32 x 32 px) */
static void	get_window_size(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 32;
}

static void	image_init(t_game *game)
{
	game->img_bckgnd = mlx_xpm_file_to_image(game->mlx,
			"assets/images/0.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/images/1.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/images/down.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/images/C.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/images/E.xpm", &game->img_w, &game->img_h);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves_count = 0;
	game->end_game = 0;
	image_init(game);
	render_map(game);
}
