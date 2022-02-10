/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:52:28 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/02/10 05:52:28 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	release_memory(char **map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	release_memory(game->map);
	mlx_destroy_image(game->mlx, game->img_hooks->img_wall);
	mlx_destroy_image(game->mlx, game->img_hooks->img_bckgnd);
	mlx_destroy_image(game->mlx, game->img_hooks->img_collect);
	mlx_destroy_image(game->mlx, game->img_hooks->img_exit);
	mlx_destroy_image(game->mlx, game->img_hooks->img_player);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}