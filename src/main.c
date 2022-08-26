/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:23:27 by brickard          #+#    #+#             */
/*   Updated: 2022/08/25 18:00:07 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->game.collect);
	mlx_destroy_image(vars->mlx, vars->game.empty);
	mlx_destroy_image(vars->mlx, vars->game.exit);
	mlx_destroy_image(vars->mlx, vars->game.player);
	mlx_destroy_image(vars->mlx, vars->game.wall);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->game.map);
	free(vars);
	exit(0);
}

void	print_steps(t_vars *vars)
{
	if (vars->game.steps != 0)
	{
		write(1, "STEPS: ", 8);
		ft_putnbr_fd(vars->game.steps, 2);
		write(1, "\n", 1);
	}
	vars->game.steps++;
}

int	key_pressed(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	if (keycode == 53)
		exit(0);
	x = vars->game.player_x;
	y = vars->game.player_y;
	if (keycode == 13 && vars->game.map[y - 1][x] != '1')
		vars->game.player_y -= 1;
	if (keycode == 0 && vars->game.map[y][x - 1] != '1')
		vars->game.player_x -= 1;
	if (keycode == 1 && vars->game.map[y + 1][x] != '1')
		vars->game.player_y += 1;
	if (keycode == 2 && vars->game.map[y][x + 1] != '1')
		vars->game.player_x += 1;
	if (vars->game.map[vars->game.player_y][vars->game.player_x] == 'E' &&
		vars->game.c_collectable != 0)
	{
		vars->game.player_x = x;
		vars->game.player_y = y;
	}
	if (x != vars->game.player_x || y != vars->game.player_y)
		draw(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;

	if (argc != 2)
		error("No arguments passed to a program.");
	vars = malloc(sizeof(t_vars));
	if (!vars)
		error("Malloc error");
	init_counters(vars);
	if (map_parser(argv[1], vars))
		return (1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->game.map_width * 50,
			vars->game.map_height * 50, "so_long");
	init_sprites(vars);
	draw(vars);
	mlx_hook(vars->win, 2, 0, key_pressed, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}
