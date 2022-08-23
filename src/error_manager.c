/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:02:24 by brickard          #+#    #+#             */
/*   Updated: 2022/08/23 15:16:29 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *e)
{
	write(2, "Error\n", 6);
	write(2, e, ft_strlen(e));
	write(2, "\n", 1);
	exit(1);
}