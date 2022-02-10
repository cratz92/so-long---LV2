/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:07:04 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 05:09:45 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* images size of (32 x 32 px) */
static void	get_window_size(t_game *game)
{
	int i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i] != '\0')
		i++;
	game->map_h = i * 32;
}

static void	image_init(t_game *game)
{
	game->img_hooks->img_bckgnd = mlx_png_file_to_image(game->mlx, "assets/images/0.png", &game->img_w, &game->img_h);
	game->img_hooks->img_wall = mlx_png_file_to_image(game->mlx, "assets/images/1.png", &game->img_w, &game->img_h);
	game->img_hooks->img_player = mlx_png_file_to_image(game->mlx, "assets/images/P.png", &game->img_w, &game->img_h);
	game->img_hooks->img_collect = mlx_png_file_to_image(game->mlx, "assets/images/C.png", &game->img_w, &game->img_h);
	game->img_hooks->img_exit = mlx_png_file_to_image(game->mlx, "assets/images/E.png", &game->img_w, &game->img_h);
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