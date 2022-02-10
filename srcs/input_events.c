/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:51:42 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 05:51:42 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_c->y][game->player_c->x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_c->y + 1][game->player_c->x] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_c->y][game->player_c->x] == '1'
		|| game->map[game->player_c->y][game->player_c->x] == 'E')
		game->player_c->y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_c->y][game->player_c->x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_c->y][game->player_c->x] = 'P';
		game->map[game->player_c->y + 1][game->player_c->x] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_c->y][game->player_c->x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_c->y - 1][game->player_c->x] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_c->y][game->player_c->x] == '1'
		|| game->map[game->player_c->y][game->player_c->x] == 'E')
		game->player_c->y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_c->y][game->player_c->x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_c->y][game->player_c->x] = 'P';
		game->map[game->player_c->y - 1][game->player_c->x] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_c->y][game->player_c->x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_c->y][game->player_c->x - 1] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_c->y][game->player_c->x] == '1'
		|| game->map[game->player_c->y][game->player_c->x] == 'E')
		game->player_c->x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_c->y][game->player_c->x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_c->y][game->player_c->x] = 'P';
		game->map[game->player_c->y][game->player_c->x - 1] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_c->y][game->player_c->x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_c->y][game->player_c->x + 1] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_c->y][game->player_c->x] == '1'
		|| game->map[game->player_c->y][game->player_c->x] == 'E')
		game->player_c->x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_c->y][game->player_c->x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_c->y][game->player_c->x] = 'P';
		game->map[game->player_c->y][game->player_c->x + 1] = '0';
		game->moves_count++;
		render_map(game);
	}
}