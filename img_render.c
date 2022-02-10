/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:08:22 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 05:08:22 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

static void	render_player(t_game *game, void *img, int x, int y)
{
	game->player_c->x = x;
	game->player_c->y = y;
	render_img(game, img, x, y);
}

static void	render_exit_img(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_hooks->img_exit);
		game->img_hooks->img_exit = mlx_png_file_to_image(game->mlx, "assets/images/E2.png", &game->img_w, &game->img_h);
	}
	render_img(game, game->img_hooks->img_exit, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				render_img(game, game->img_hooks->img_wall, x, y);
			else if (game->map[y][x] == '0')
				render_img(game, game->img_hooks->img_bckgnd, x, y);
			else if (game->map[y][x] == 'C')
				render_img(game, game->img_hooks->img_collect, x, y);
			else if (game->map[y][x] == 'P')
				render_player(game, game->img_hooks->img_player, x, y);
			else if (game->map[y][x] == 'E')
				render_exit_img(game, x, y);
			x++;
		}
		y++;
	}
}