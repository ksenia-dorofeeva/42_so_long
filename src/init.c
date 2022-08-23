/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:53:01 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:16:20 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_counters(t_vars *vars)
{
	vars->game.c_collectable = 0;
	vars->game.c_empty = 0;
	vars->game.c_player = 0;
	vars->game.c_exit = 0;
	vars->game.map_width = 0;
	vars->game.steps = 0;
}

void	init_sprites(t_vars *vars)
{
	int	a;
	int	b;

	a = 50;
	b = 50;
	vars->game.wall = mlx_xpm_file_to_image(vars->mlx,
			"./images/wall.xpm", &a, &b);
	vars->game.empty = mlx_xpm_file_to_image(vars->mlx,
			"./images/empty.xpm", &a, &b);
	vars->game.exit = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &a, &b);
	vars->game.collect = mlx_xpm_file_to_image(vars->mlx,
			"./images/collect.xpm", &a, &b);
	vars->game.player = mlx_xpm_file_to_image(vars->mlx,
			"./images/player.xpm", &a, &b);
}
