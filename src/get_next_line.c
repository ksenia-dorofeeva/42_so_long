/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:17:14 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:16:23 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_read_str(int fd, char *str_buf, long i)
{
	char	*buf;

	if (!str_buf)
	{
		str_buf = (char *)malloc(sizeof(char));
		if (!str_buf)
			return (NULL);
		str_buf[0] = '\0';
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str_buf, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		str_buf = ft_strjoin(str_buf, buf);
	}
	free(buf);
	return (str_buf);
}

char	*ft_line(char *str_buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!str_buf[i])
		return (NULL);
	while (str_buf[i] && str_buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1 + (str_buf[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (str_buf[i] && str_buf[i] != '\n')
	{
		line[i] = str_buf[i];
		i++;
	}
	if (str_buf[i] == '\n')
	{
		line[i] = str_buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trim(char *str_buf)
{
	int		i;
	int		j;
	char	*str_trim;

	i = 0;
	while (str_buf[i] && str_buf[i] != '\n')
		i++;
	if (!str_buf[i])
	{
		free(str_buf);
		return (NULL);
	}
	str_trim = (char *)malloc(sizeof(char) * ft_strlen(str_buf) - i + 1);
	if (!str_trim)
		return (NULL);
	i++;
	j = 0;
	while (str_buf[i])
		str_trim[j++] = str_buf[i++];
	str_trim[j] = '\0';
	free(str_buf);
	return (str_trim);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*str_buf;
	long		i;

	i = 1;
	if (read(fd, str_buf, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_buf = ft_read_str(fd, str_buf, i);
	if (!str_buf)
		return (NULL);
	str = ft_line(str_buf);
	str_buf = ft_trim(str_buf);
	return (str);
}
