/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:55:27 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 16:06:49 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 100

typedef int	t_bool;

typedef struct s_game
{	
	int		map_height;
	int		map_width;
	char	**map;
	void	*player;
	void	*wall;
	void	*empty;
	void	*exit;
	void	*collect;
	int		player_x;
	int		player_y;
	int		c_collectable;
	int		c_player;
	int		c_exit;
	int		c_empty;
	int		steps;
}	t_game;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_game	game;
}	t_vars;

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str_buf, long i);
char	*ft_line(char *str_buf);
char	*ft_trim(char *str_buf);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);

int		map_parser(char *map, t_vars *vars);
void	error(char *e);
void	init_counters(t_vars *vars);
void	init_sprites(t_vars *vars);
void	draw_map(t_vars *vars);
int		draw(t_vars *vars);
void	print_steps(t_vars *vars);
int		line_valid(char *line, t_bool first_or_last, t_vars *vars);
void	check(t_vars *vars);

#endif