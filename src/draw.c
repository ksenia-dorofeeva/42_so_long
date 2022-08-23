/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:56:31 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:16:33 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->game.map_height)
	{
		j = -1;
		while (++j < vars->game.map_width)
		{
			if (vars->game.map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->game.empty, j * 50, i * 50);
			if (vars->game.map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->game.exit, j * 50, i * 50);
			if (vars->game.map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->game.wall, j * 50, i * 50);
			if (vars->game.map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->game.collect, j * 50, i * 50);
		}
	}
}

int	draw_player(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->game.player,
		vars->game.player_x * 50, vars->game.player_y * 50);
	return (0);
}

int	draw(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->game.player_x;
	y = vars->game.player_y;
	print_steps(vars);
	if (vars->game.map[y][x] == 'C')
	{
		vars->game.map[y][x] = '0';
		vars->game.c_collectable -= 1;
	}
	draw_map(vars);
	draw_player(vars);
	if (vars->game.map[y][x] == 'E' && vars->game.c_collectable == 0)
	{
		write(1, "YOU WON!\n", 9);
		exit(0);
	}
	return (1);
}
