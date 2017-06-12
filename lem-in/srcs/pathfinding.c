/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/02 18:09:40 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_solution(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		n;

	ft_printf("display_solution\n");
	i = data->len;
	if (data->best == NULL || data->best[0] != data->end - 1)
		ft_error(data, "No solution");
	i = data->len;
	while (i-- > 0)
	{
		n = 0;
		tmp = data->r;
		while (tmp != NULL)
		{
			if (data->best[i] > 0 && n + 1 == data->best[i])
				ft_printf("%s -> ", tmp->content);
			n++;
			tmp = tmp->next;
		}
	}
	ft_printf("shortest way is %d long\n", data->len);
}

void	shortening_best_way(t_data *data)
{
	t_pos i;

	i.x = -1;
	while (++i.x < data->len)
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
	data->lmax = data->len;
	while (++sol.x < (data->lmax + data->rooms) * 2)
	{
		sol.y = 0;
		while (++sol.y < (data->lmax + 1) * 2)
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

void	reset_matrix(t_data *data, int room)
{
	t_pos pos;

	pos.x = data->rooms;
	while (pos.x-- > 0)
	{
		if (data->p[room][pos.x] != 0)
		{
			// data->p[room][pos.x] = 0;
			data->p[pos.x][room] = 0;
			break ;
		}
	}
	pos.x = -1;
	while (++pos.x < data->rooms)
	{
		pos.y = -1;
		while (++pos.y < data->rooms)
			data->p[pos.y][pos.x] = (int)ft_abs(data->p[pos.y][pos.x]);
	}
}

int		hacking_way(t_data *data, int room, int turn, int try)
{
	if (turn != 1 && room == data->start - 1)
	{
		data->s[try][turn - 1] = -1;
		return (1);
	}
	if (data->p[room][data->end - 1] > 0)
	{
		data->s[try][turn] = data->end - 1;
		return (1);
	}
	return (0);
}

int		get_ways(t_data *data, int room, int turn, int try)
{
	int pos;

	data->been[room] = 1;
	if (hacking_way(data, room, turn, try))
		return (1);
	else
	{
		pos = -1;
		while (++pos < data->rooms)
		{
			if (data->p[room][pos] > 0 && data->been[pos] == 0)
			{
				// data->p[room][pos] *= -1;
				data->p[pos][room] *= -1;
				data->s[try][turn++] = pos;
				if (turn > (data->len + 1) * 2)
					break ;
				else
					return (get_ways(data, pos, turn, try));
			}
		}
	}
	reset_matrix(data, room);
	return (0);
}

void	set(t_data *data)
{
	t_pos pos;

	pos.x = -1;
	while (++pos.x < (data->len + data->rooms) * 2)
	{
		pos.y = -1;
		while (++pos.y < (data->len + 1) * 2)
			data->s[pos.x][pos.y] = -1;
	}
}

void	pathfinding(t_data *data)
{
	int try;
	int i;

	if (!(data->s = ft_inttab((data->len + 1) * 2, (data->len + data->rooms) * 2)) || !(data->been = *ft_inttab(data->rooms, 1)))
		ft_error(data, "Error malloc");
	set(data);
	try = -1;
	while (++try < (data->len + data->rooms) * 2)
	{
		i = -1;
		while (++i < data->rooms)
			data->been[i] = 0;
		data->s[try][0] = data->start - 1;
		get_ways(data, data->start - 1, 1, try);
	}
	get_best_way(data);
	//shortening_best_way(data);
}
