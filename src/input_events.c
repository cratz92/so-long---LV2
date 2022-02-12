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

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y + 1][game->player_x] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_y -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y - 1][game->player_x] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x - 1] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves_count++;
		game->end_game = 1;
		render_map(game);
	}
	else if (game->map[game->player_y][game->player_x] == '1'
		|| game->map[game->player_y][game->player_x] == 'E')
		game->player_x += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->n_collect -= 1;
		game->map[game->player_y][game->player_x] = 'P';
		game->map[game->player_y][game->player_x + 1] = '0';
		game->moves_count++;
		render_map(game);
	}
}

void	sprite_animation(char instruction, t_game *game)
{
	if (instruction == 'u')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/images/up.xpm", &game->img_w, &game->img_h);
	else if (instruction == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/images/down.xpm", &game->img_w, &game->img_h);
	else if (instruction == 'r')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/images/right.xpm", &game->img_w, &game->img_h);
	else if (instruction == 'l')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"assets/images/left.xpm", &game->img_w, &game->img_h);
}
