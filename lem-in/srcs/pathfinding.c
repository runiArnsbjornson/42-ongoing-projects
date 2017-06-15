/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/15 16:54:26 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_solution(t_data *data)
{
	t_list	*tmp;
	t_pos	i;
	t_pos	j;

	ft_printf("display_solution\n");
	if (data->best == NULL || data->best[0] == data->best[1])
		ft_error(data, "No solution");
	j.y = 0;
	while (++j.y <= data->len)
	{
		i.y = 0;
		if (++i.y <= j.y)
		{
			tmp = data->r;
			j.x = data->best[i.y];
			while (tmp && j.x--)
				tmp = tmp->next;
			ft_printf("L%d-%s ", j.y, tmp->content);
		}
		ft_printf("\n");
	}
	ft_printf("shortest way is %d long\n", data->len);
}

void	shortening_best_way(t_data *data)
{
	t_pos i;

	i.x = -1;
	while (++i.x < data->lmax)
	{
		i.y = 0;
		while (++i.y < i.x)
		{
			if (data->best[i.y] == data->end - 1)
				break ;
			if (data->best[i.x] == data->best[i.y])
			{
				ft_printf("doublon best[%d]=%d best[%d]=%d\n", i.x, data->best[i.x], i.y, data->best[i.y]);
			}
		}
	}
}

void	get_best_way(t_data *data)
{
	t_pos sol;

	sol.x = -1;
	while (++sol.x < data->lmax + data->rooms)
	{
		sol.y = -1;
		while (++sol.y < data->lmax)
		{
			if (data->s[sol.x][sol.y] == data->end - 1 && sol.y < data->len &&
				data->s[sol.x][0] == data->start - 1)
			{
				data->best = data->s[sol.x];
				data->len = sol.y;
				break ;
			}
		}
	}
}

void	reset_matrix(t_data *data, int room, int turn, int try)
{
	t_pos pos;

	ft_printf(BOL GRN "enter RESET room=%d turn=%d try=%d\n" RES, room, turn, try);
	ft_putinttab(data->p, data->rooms);
	if (turn > 1)
		data->p[data->s[try][turn - 2]][data->s[try][turn - 1]] = 0;
	pos.x = -1;
	while (++pos.x < data->rooms)
	{
		pos.y = -1;
		while (++pos.y < data->rooms)
			data->p[pos.y][pos.x] = (int)ft_abs(data->p[pos.y][pos.x]);
	}
	ft_putinttab(data->p, data->rooms);
}

void	reset_hacked_matrix(t_data *data, int room, int turn, int try)
{
	t_pos pos;

	if (turn > 1)
	{
		pos.y = 0;
		pos.x = -1;
		while (++pos.x < data->rooms)
		{
			if (data->p[pos.x][data->s[try][turn - 1]] > 0)
				pos.y++;
		}
		if (pos.y > 1)
			reset_matrix(data, room, turn, try);
		else
			reset_hacked_matrix(data, room, turn - 1, try);
	}
}


int		hacking_way(t_data *data, int room, int turn, int try)
{

	if (data->p[room][data->end - 1] > 0)
	{
		// ft_printf(BLU "END hack\n" RES);
		data->p[room][data->end - 1] *= -1;
		data->s[try][turn] = data->end - 1;
		return (1);
	}
	return (0);
}

int		get_ways(t_data *data, int room, int turn, int try)
{
	int pos;
	// int i;

	data->mark[room] = 1;
	// i = -1;
	// while (++i < data->rooms)
	// 	ft_printf("[%s%d%s]%c", data->mark[i] == 1 ? GRN : RED, data->mark[i], RES, i == data->rooms - 1 ? '\n': ' ');
	if (hacking_way(data, room, turn, try) == 1)
		reset_hacked_matrix(data, room, turn, try);
	else
	{
		// ft_printf(YEL "enter ELSE room=%d turn=%d try=%d\n" RES, room, turn, try);
		// ft_putinttab(data->p, data->rooms);
		pos = -1;
		while (++pos < data->rooms)
		{
			if (data->p[room][pos] > 0)
			{
				if (data->mark[pos] == 0)
				{
					data->p[room][pos] *= -1;
					data->s[try][turn++] = pos;
					// ft_printf(BLU "NO MARK room=%d pos=%d\n" RES, room, pos);
					// ft_putinttab(data->p, data->rooms);
					// ft_putinttab(data->s, data->lmax);
					return (get_ways(data, pos, turn, try));
				}
				else
				{
					// ft_printf(BLU "LOOP hack room=%d pos=%d turn=%d try=%d\n" RES, room, pos, turn, try);
					// ft_putinttab(data->s, data->lmax);
					data->p[room][pos] *= -1;
				}
			}
		}
		reset_matrix(data, room, turn, try);
	}
	return (0);
}

void	set(t_data *data)
{
	t_pos pos;

	pos.x = -1;
	while (++pos.x < data->lmax + data->rooms)
	{
		pos.y = -1;
		while (++pos.y < data->lmax)
			data->s[pos.x][pos.y] = -1;
	}
}

void	pathfinding(t_data *data)
{
	int try;
	int i;

	data->lmax = data->lmax * 2 + 1;
	data->len = data->lmax;
	if (!(data->s = ft_inttab(data->lmax, data->lmax + data->rooms)) || !(data->mark = (int *)ft_memalloc(sizeof(int) * (unsigned long)(data->rooms + 1))))
		ft_error(data, "Error malloc");
	set(data);
	try = -1;
	while (++try < data->lmax + data->rooms)
	{
		i = -1;
		while (++i < data->rooms)
		{
			data->mark[i] = 0;
			data->p[i][data->start - 1] = 0;
		}
		data->s[try][0] = data->start - 1;
		get_ways(data, data->start - 1, 1, try);
	}
	get_best_way(data);
	//shortening_best_way(data);
}
