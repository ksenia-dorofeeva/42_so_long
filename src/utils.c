/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:47:28 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:16:15 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m = -n;
	}
	else
		m = n;
	if (m >= 0)
	{		
		if (m / 10 > 0)
			ft_putnbr_fd(m / 10, fd);
		ft_putchar_fd(m % 10 + '0', fd);
	}
}
