/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:17:51 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/02 17:19:38 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		find(t_data *data, t_pos pos)
{
	t_pos	tmp;
	int		flag_player;
	int		size;

	flag_player = 0;
	size = 0;
	tmp.y = pos.y;
	while (tmp.y < pos.y + data->piece->y)
	{
		tmp.x = pos.x;
		while (tmp.x < pos.x + data->piece->x)
		{
			if (data->piece->piece[tmp.y - pos.y][tmp.x - pos.x] == '*' &&
		data->board->board[tmp.y][tmp.x] == data->player)
				++flag_player;
			if (!(data->piece->piece[tmp.y - pos.y][tmp.x - pos.x] == '*' &&
		data->board->board[tmp.y][tmp.x] != '.'))
				++size;
			tmp.x++;
		}
		tmp.y++;
	}
	if (flag_player == 1 && size == (data->piece->y * data->piece->x - 1))
		return (1);
	return (0);
}

int		search_p2(t_data *data)
{
	t_pos pos;

	pos.y = 0;
	while (pos.y <= data->board->y - data->piece->y)
	{
		pos.x = 0;
		while (pos.x <= data->board->x - data->piece->x)
		{
			if (find(data, pos) == 1)
			{
				ft_putnbr_fd(pos.y, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(pos.x, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			pos.x++;
		}
		pos.y++;
	}
	ft_putstr_fd("0 0\n", 1);
	return (0);
}

int		fill_p2(t_data *data)
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
				return (1);
			}
			pos.y++;
		}
		pos.x++;
	}
	ft_putstr_fd("0 0\n", 1);
	return (0);
}

int		search(t_data *data)
{
	t_pos pos;

	pos.y = data->board->y - data->piece->y;
	while (pos.y >= 0)
	{
		pos.x = data->board->x - data->piece->x;
		while (pos.x >= 0)
		{
			if (find(data, pos) == 1)
			{
				ft_putnbr_fd(pos.y, 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(pos.x, 1);
				ft_putchar_fd('\n', 1);
				return (1);
			}
			pos.x--;
		}
		pos.y--;
	}
	ft_putstr_fd("0 0\n", 1);
	return (0);
}

int		fill(t_data *data)
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
				return (1);
			}
			pos.y--;
		}
		pos.x--;
	}
	ft_putstr_fd("0 0\n", 1);
	return (0);
}
