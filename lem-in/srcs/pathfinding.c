/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/16 15:57:56 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_solution(t_data *d)
{
	int		in;
	int		i;
	int		y;

	ft_printf("display_solution %d\n", d->ants);
	if (d->best == NULL || d->best[0] == d->best[1])
		ft_error(d, "No solution");
	if (d->max == NULL)
		if (!(d->max = (int *)ft_memalloc(sizeof(int) * (unsigned int)d->ants + 1)))
			ft_error(d, "Error malloc");
	y = 0;
	in = 1;
	while (y != d->len)
	{
		i = 0;
		while(++i < in)
		{
			y = 0;
			if (y != d->len)
			{
				ft_printf("L%d-%s ", i, get_content(d->r, d->best[y]));
				y++;
			}
		}
		ft_printf("\n");
		if (in <= d->ants)
			in++;
	}
	ft_printf("shortest way is %d long\n", d->len);
}

void	shortening_best_way(t_data *d)
{
	t_pos i;

	i.x = -1;
	while (++i.x < d->lmax)
	{
		i.y = 0;
		while (++i.y < i.x)
		{
			if (d->best[i.y] == d->end - 1)
				break ;
			if (d->best[i.x] == d->best[i.y])
			{
				ft_printf("doublon best[%d]=%d best[%d]=%d\n", i.x, d->best[i.x], i.y, d->best[i.y]);
			}
		}
	}
}

void	get_best_way(t_data *d)
{
	t_pos sol;

	sol.x = -1;
	while (++sol.x < d->lmax + d->rooms)
	{
		sol.y = -1;
		while (++sol.y < d->lmax)
		{
			if (d->s[sol.x][sol.y] == d->end - 1 && sol.y < d->len &&
				d->s[sol.x][0] == d->start - 1)
			{
				d->best = d->s[sol.x];
				d->len = sol.y;
				break ;
			}
		}
	}
}

void	reset_matrix(t_data *d, int room, int turn, int try)
{
	t_pos pos;

	ft_printf(BOL GRN "enter RESET room=%d turn=%d try=%d\n" RES, room, turn, try);
	ft_putinttab(d->p, d->rooms);
	if (turn > 1)
		d->p[d->s[try][turn - 2]][d->s[try][turn - 1]] = 0;
	pos.x = -1;
	while (++pos.x < d->rooms)
	{
		pos.y = -1;
		while (++pos.y < d->rooms)
			d->p[pos.y][pos.x] = (int)ft_abs(d->p[pos.y][pos.x]);
	}
	ft_putinttab(d->p, d->rooms);
}

void	reset_hacked_matrix(t_data *d, int room, int turn, int try)
{
	t_pos pos;

	if (turn > 1)
	{
		pos.y = 0;
		pos.x = -1;
		while (++pos.x < d->rooms)
		{
			if (d->p[pos.x][d->s[try][turn - 1]] > 0)
				pos.y++;
		}
		if (pos.y > 1)
			reset_matrix(d, room, turn, try);
		else
			reset_hacked_matrix(d, room, turn - 1, try);
	}
}


int		hacking_way(t_data *d, int room, int turn, int try)
{

	if (d->p[room][d->end - 1] > 0)
	{
		// ft_printf(BLU "END hack\n" RES);
		d->p[room][d->end - 1] *= -1;
		d->s[try][turn] = d->end - 1;
		return (1);
	}
	return (0);
}

int		get_ways(t_data *d, int room, int turn, int try)
{
	int pos;
	// int i;

	d->mark[room] = 1;
	// i = -1;
	// while (++i < d->rooms)
	// 	ft_printf("[%s%d%s]%c", d->mark[i] == 1 ? GRN : RED, d->mark[i], RES, i == d->rooms - 1 ? '\n': ' ');
	if (hacking_way(d, room, turn, try) == 1)
		reset_hacked_matrix(d, room, turn, try);
	else
	{
		// ft_printf(YEL "enter ELSE room=%d turn=%d try=%d\n" RES, room, turn, try);
		// ft_putinttab(d->p, d->rooms);
		pos = -1;
		while (++pos < d->rooms)
		{
			if (d->p[room][pos] > 0)
			{
				if (d->mark[pos] == 0)
				{
					d->p[room][pos] *= -1;
					d->s[try][turn++] = pos;
					// ft_printf(BLU "NO MARK room=%d pos=%d\n" RES, room, pos);
					// ft_putinttab(d->p, d->rooms);
					// ft_putinttab(d->s, d->lmax);
					return (get_ways(d, pos, turn, try));
				}
				else
				{
					// ft_printf(BLU "LOOP hack room=%d pos=%d turn=%d try=%d\n" RES, room, pos, turn, try);
					// ft_putinttab(d->s, d->lmax);
					d->p[room][pos] *= -1;
				}
			}
		}
		reset_matrix(d, room, turn, try);
	}
	return (0);
}

void	set(t_data *d)
{
	t_pos pos;

	pos.x = -1;
	while (++pos.x < d->lmax + d->rooms)
	{
		pos.y = -1;
		while (++pos.y < d->lmax)
			d->s[pos.x][pos.y] = -1;
	}
}

void	pathfinding(t_data *d)
{
	int try;
	int i;

	d->lmax = d->lmax * 2 + 1;
	d->len = d->lmax;
	if (!(d->s = ft_inttab(d->lmax, d->lmax + d->rooms)) || !(d->mark = (int *)ft_memalloc(sizeof(int) * (unsigned long)(d->rooms + 1))))
		ft_error(d, "Error malloc");
	set(d);
	try = -1;
	while (++try < d->lmax + d->rooms)
	{
		i = -1;
		while (++i < d->rooms)
		{
			d->mark[i] = 0;
			d->p[i][d->start - 1] = 0;
		}
		d->s[try][0] = d->start - 1;
		get_ways(d, d->start - 1, 1, try);
	}
	get_best_way(d);
	//shortening_best_way(d);
}
