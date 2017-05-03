/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:55:26 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/03 15:47:06 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	block_p2(t_data *data, int *ref)
{
	t_pos pos;

	pos.x = data->board->x - data->piece->x;
	while (pos.x >= 0)
	{
		pos.y = data->board->y - data->piece->y;
		while (pos.y >= 0)
		{
			if (find(data, pos) == 1)
			{
				ft_putnbr_fd(pos.y, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(pos.x, 1);
				ft_putchar_fd('\n', 1);
				if (pos.x == data->board->x || pos.y == data->board->y)
					ref[5] = 2;
				return ;
			}
			pos.y--;
		}
		pos.x--;
	}
	ft_putstr_fd("0 0\n", 1);
}

void	block(t_data *data, int *ref)
{
	t_pos pos;

	pos.x = 0;
	while (pos.x <= data->board->x - data->piece->x)
	{
		pos.y = 0;
		while (pos.y <= data->board->y - data->piece->y)
		{
			if (find(data, pos) == 1)
			{
				ft_putnbr_fd(pos.y, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(pos.x, 1);
				ft_putchar_fd('\n', 1);
				if (pos.x == 0 || pos.y == 0)
					ref[5] = 2;
				return ;
			}
			pos.y++;
		}
		pos.x++;
	}
	ft_putstr_fd("0 0\n", 1);
}
