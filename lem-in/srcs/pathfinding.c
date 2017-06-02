/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/02 17:53:42 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_solution(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		n;

	ft_printf("display_solution\n");
	i = data->rooms;
	if (!data->best_way || data->best_way[0] != data->end - 1)
		ft_error(data, "No solution");
	i = data->rooms;
	while (i-- > 0)
	{
		n = 0;
		tmp = data->r;
		while (tmp != NULL)
		{
			if (data->best_way[i] > 0 && n + 1 == data->best_way[i])
				ft_printf("%s -> ", tmp->content);
			n++;
			tmp = tmp->next;
		}
	}
	ft_printf("shortest way is %d long\n", data->len);
}

int		realloc_next(t_data *data, int turn)
{
	int i;

	ft_printf("realloc_next\n");
	free(data->next);
	if (!(data->next = (int*)ft_memalloc(sizeof(int) * (unsigned long)(data->rooms + 1))))
		return (1);
	i = -1;
	while (data->s[turn][++i])
		data->next[i] = data->s[turn][i];
	return (0);
}

int		search_room(t_data *data, int ref)
{
	t_pos pos;

	ft_printf("search_room\n");
	pos.x = 0;
	while (++pos.x < data->rooms)
	{
		pos.y = 0;
		while (++pos.y < data->rooms)
			if (data->p[pos.x][pos.y] == ref * -1)
			{
				data->p[pos.x][pos.y] *= -1;
				return (pos.x);
			}
	}
	return (0);
}

int		shorten_best_way(t_data *data)
{
	int	i;
	int	search;

	ft_printf("shorten_best_way\n");
	i = 0;
	search = 0;
	if (!(data->best_way = (int*)ft_memalloc(sizeof(int) * (unsigned long)data->len)))
		ft_error(data, "Error malloc");
	while (data->bway[i] != 0)
		i++;
	while (search < data->len && data->bway[--i] != 0)
		data->best_way[search++] = data->bway[i];
	return (0);
}

// int		get_best_way(t_data *data)
// {

// }

void	reset_matrix(t_data *data, int room)
{
	t_pos pos;

	pos.x = data->rooms;
	while (pos.x-- > 0)
	{
		if (data->p[room][pos.x] != 0)
		{
			data->p[room][pos.x] = 0;
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

int		get_ways(t_data *data, int room, int turn, int try)
{
	int pos;

	pos = -1;
	if (data->p[room][data->end - 1] > 0)
	{
		data->s[try][turn] = data->end - 1;
		return (1);
	}
	else
	{
		while (++pos < data->rooms)
		{
			if (data->p[room][pos] > 0)
			{
				data->p[room][pos] *= -1;
				data->p[pos][room] *= -1;
				data->s[try][turn++] = pos;
				if (pos == (data->end - 1))
					return (1);
				else
					return (get_ways(data, pos, turn, try));
			}
			if (turn > data->rooms)
				ft_error(data, "No solution");
		}
	}
	reset_matrix(data, room);
	return (0);
}

void	pathfinding(t_data *data)
{
	int try;

	if (!(data->s = ft_inttab(data->rooms, data->rooms)) ||
		!(data->next = (int *)ft_memalloc(sizeof(int) * ((unsigned long)data->rooms + 1))))
		ft_error(data, "Error malloc");
	try = -1;
	while (++try < data->rooms)
	{
		data->s[try][0] = data->start - 1;
		get_ways(data, data->start - 1, 1, try);
	}
}
