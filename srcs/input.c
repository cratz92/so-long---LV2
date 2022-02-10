/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:51:03 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 05:51:03 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	input_response(int keycode, t_game *game)
{
	if (keycode == Key_W || keycode == Key_Arrow_Up)
	{
		game->player_c->y -= 1;
		move_up(game);
	}
	else if (keycode == Key_S || keycode == Key_Arrow_Down)
	{
		game->player_c->y += 1;
		move_down(game);
	}
	else if (keycode == Key_D || keycode == Key_Arrow_Right)
	{
		game->player_c->x += 1;
		move_right(game);
	}
	else if (keycode == Key_A || keycode == Key_Arrow_Left)
	{
		game->player_c->x -= 1;
		move_left(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == Key_ESQ)
		exit_game(game);
	else if (!game->end_game)
	{
		input_response(keycode, game);
		ft_printf("Moves: %d\n", game->moves_count);
	}
	return (0);
}

/* codes used on hook function, came from X11/X.h docs, 
https://code.woboq.org/qt5/include/X11/X.h.html */
void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, render_map, game);
}