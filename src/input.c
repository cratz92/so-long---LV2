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

#include "../includes/so_long.h"

static void	input_response(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->player_y -= 1;
		sprite_animation('u', game);
		move_up(game);
	}
	else if (keycode == KEY_S)
	{
		game->player_y += 1;
		sprite_animation('d', game);
		move_down(game);
	}
	else if (keycode == KEY_D)
	{
		game->player_x += 1;
		sprite_animation('r', game);
		move_right(game);
	}
	else if (keycode == KEY_A)
	{
		game->player_x -= 1;
		sprite_animation('l', game);
		move_left(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESQ || keycode == KEY_Q)
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
