/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 09:48:25 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:40:33 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_height(char *map)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error("Wrong file path.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height += 1;
		free(line);
	}
	close(fd);
	return (height);
}

void	save_to_line(char *map_line, char type, int *counter)
{
	*map_line = type;
	*counter += 1;
}

char	*get_map_line(char *line, t_vars *vars, int y)
{
	int		i;
	char	*map_line;

	i = -1;
	map_line = malloc(sizeof(char *) * vars->game.map_width);
	if (!map_line)
		error("Malloc error");
	while (++i < vars->game.map_width)
	{
		if (line[i] == '0')
			save_to_line(&map_line[i], '0', &vars->game.c_empty);
		if (line[i] == '1')
			map_line[i] = '1';
		if (line[i] == 'C')
			save_to_line(&map_line[i], 'C', &vars->game.c_collectable);
		if (line[i] == 'P')
		{
			vars->game.player_x = i;
			vars->game.player_y = y;
			save_to_line(&map_line[i], '0', &vars->game.c_player);
		}
		if (line[i] == 'E')
			save_to_line(&map_line[i], 'E', &vars->game.c_exit);
	}
	return (map_line);
}

int	map_parser(char *map, t_vars *vars)
{
	char	*line;
	int		fd;
	int		i;

	vars->game.map_height = get_map_height(map);
	vars->game.map = malloc(sizeof(char *) * vars->game.map_height);
	if (!vars->game.map)
		error("Malloc error");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error("Wrong file path.");
	i = -1;
	while (++i < vars->game.map_height)
	{
		line = get_next_line(fd);
		if (!line)
			error("Malloc error");
		if (line_valid(line, (i == 0 || vars->game.map_height - i == 1), vars))
			error("Wrong map.");
		vars->game.map[i] = get_map_line(line, vars, i);
		free(line);
	}
	close(fd);
	check(vars);
	return (0);
}
