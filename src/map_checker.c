/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:30:17 by brickard          #+#    #+#             */
/*   Updated: 2022/08/25 13:53:31 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_valid(char *line, t_bool first_or_last, t_vars *vars)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len -= 1;
	}
	if (vars->game.map_width != 0 && vars->game.map_width != len)
		error("Map has curved edges!");
	vars->game.map_width = len;
	i = -1;
	while (++i < len)
	{
		if (i == 0 || len - i == 1 || first_or_last)
			if (line[i] != '1')
				return (1);
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
			return (1);
	}
	return (0);
}

void	check(t_vars *vars)
{
	if (vars->game.c_collectable == 0)
		error("No collectables on the map.");
	if (vars->game.c_empty == 0)
		error("No free space on the map.");
	if (vars->game.c_exit != 1)
		error("Wrong number of exits");
	if (vars->game.c_player != 1)
		error("Wrong number of players");
}
