/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:54:15 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/08 13:28:07 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_display(t_display *color)
{
	color->grn = 0;
	color->red = 0;
	color->wht = 0;
}

void	display_percent(t_data *data, t_display *color)
{
	int total;

	total = data->board->x * data->board->y;
	ft_putstr_fd(BMAG "P1"RES MAG" = ", 2);
	ft_putnbr_fd(color->red * 100 / total, 2);
	ft_putstr_fd("% (", 2);
	ft_putnbr_fd(color->red, 2);
	ft_putstr_fd(" spaces)\t"RES BGRN BLU"P2"RES GRN" = ", 2);
	ft_putnbr_fd(color->grn * 100 / total, 2);
	ft_putstr_fd("% (", 2);
	ft_putnbr_fd(color->grn, 2);
	ft_putstr_fd(" spaces)\t"RES BWHT"  "RES WHT" empty spaces = ", 2);
	ft_putnbr_fd(color->wht, 2);
	ft_putstr_fd("\n\n", 2);
	usleep(10000 - total > 0 ? 10000 - total : 0);
}

void	display_color(t_data *data, t_pos *pos, t_display *color)
{
	if (data->board->board[pos->y][pos->x] == P2)
	{
		color->grn++;
		ft_putstr_fd(BGRN"  "RES, 2);
	}
	else if (data->board->board[pos->y][pos->x] == P1)
	{
		color->red++;
		ft_putstr_fd(BMAG"  "RES, 2);
	}
	else
	{
		color->wht++;
		ft_putstr_fd(BWHT"  "RES, 2);
	}
}

void	display_graph(t_data *data)
{
	t_pos		pos;
	t_display	color;

	pos.y = 0;
	init_display(&color);
	ft_putstr_fd(TCLN, 2);
	while (pos.y < data->board->y)
	{
		pos.x = 0;
		while (pos.x < data->board->x)
		{
			display_color(data, &pos, &color);
			++pos.x;
		}
		ft_putchar_fd('\n', 2);
		++pos.y;
	}
	ft_putchar_fd('\n', 2);
	display_percent(data, &color);
	init_display(&color);
}
