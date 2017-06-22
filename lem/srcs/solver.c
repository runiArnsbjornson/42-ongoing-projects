/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:14:34 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/22 10:46:58 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		reset_matrix(t_data *d, int room, int turn, int try)
{
	t_pos pos;

	// ft_printf(GRN "enter RESET room=%d turn=%d try=%d\n" RES, room, turn, try);
	// ft_putinttab(d->p, d->rooms);
	if (turn > 1)
		d->p[d->s[try][turn - 2]][d->s[try][turn - 1]] = 0;
	pos.x = -1;
	while (++pos.x < d->rooms)
	{
		pos.y = -1;
		while (++pos.y < d->rooms)
			d->p[pos.x][pos.y] = (int)ft_abs(d->p[pos.x][pos.y]);
	}
	room = 0;
	// ft_putinttab(d->p, d->rooms);
	return (0);
}

int		reset_hacked(t_data *d, int room, int turn, int try)
{
	t_pos pos;

	if (turn > 1)
	{
		pos.y = 0;
		pos.x = -1;
		while (++pos.x < d->rooms)
		{
			if (d->p[d->s[try][turn - 1]][pos.x] > 0)
				pos.y++;
		}
		if (pos.y > 1)
			reset_matrix(d, room, turn, try);
		else
			reset_hacked(d, room, turn - 1, try);
	}
	return (1);
}

int		hacking_way(t_data *d, int room, int turn, int try)
{
	if (d->p[room][d->end - 1] > 0)
	{
		d->p[room][d->end - 1] *= -1;
		d->s[try][turn] = d->end - 1;
		return (1);
	}
	return (0);
}

int		get_ways(t_data *d, int room, int turn, int try)
{
	int pos;

	d->mark[room] = 1;
	if (hacking_way(d, room, turn, try))
		return (reset_hacked(d, room, turn, try));
	else
	{
		pos = -1;
		while (++pos < d->rooms)
		{
			if (d->p[room][pos] > 0)
			{
				if (d->mark[pos] == 0)
				{
					d->p[room][pos] *= -1;
					d->s[try][turn++] = pos;
					return (get_ways(d, pos, turn, try));
				}
				else
					d->p[room][pos] *= -1;
			}
		}
	}
	return (reset_matrix(d, room, turn, try));
}

void	pathfinding(t_data *d)
{
	t_pos try;

	d->lmax = d->lmax * 2 + 1;
	d->len = d->lmax;
	if (!(d->s = ft_inttab(d->lmax, d->lmax)) ||
		!(d->mark = ft_memalloc(sizeof(int) * (unsigned long)(d->rooms + 1))))
		ft_error(d, "Error malloc");
	ft_setinttab(d->s, d->lmax, -1);
	try.x = -1;
	while (++try.x < d->lmax)
	{
		try.y = -1;
		while (++try.y < d->rooms)
		{
			d->mark[try.y] = 0;
			d->p[try.y][d->start - 1] = 0;
		}
		d->s[try.x][0] = d->start - 1;
		get_ways(d, d->start - 1, 1, try.x);
		if (d->s[try.x][1] == -1)
			break ;
	}
	get_best(d);
}
