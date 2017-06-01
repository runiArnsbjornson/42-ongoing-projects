/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/01 17:35:52 by jdebladi         ###   ########.fr       */
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

int		get_best_way(t_data *data)
{
	int i;
	int search;

	ft_printf("get_best_way\n");
	i = 0;
	search = data->end - 1;
	if (!(data->bway = (int *)ft_memalloc(sizeof(int) * (unsigned long)(data->rooms + 1))))
		ft_error(data, "Error malloc");
	while (search != - 1)
	{
		if (search != 0 && search != data->start - 1)
			data->bway[i++] = search;
		search = data->way[search];
		if (search == 0)
		{
			data->bway[i++] = data->start - 1;
			break ;
		}
	}
	data->len = i;
	return (shorten_best_way(data));
}

int		get_ways(t_data *data, int turn)
{
	int room;
	t_pos pos;

	ft_printf("get_ways\n");
	room = 0;
	pos.x = -1;
	while (data->next[++pos.x] > 0)
	{
		pos.y = -1;
		while (++pos.y < data->rooms)
		{
			if (data->p[data->next[pos.x]][pos.y] > 0)
			{
				data->p[data->next[pos.x]][pos.y] *= -1;
				data->s[turn][room] = search_room(data, data->p[data->next[pos.x]][pos.y]);
				if (data->p[data->next[pos.x]][pos.y] == data->start)
					data->way[data->start - 1] = -1;
				data->way[data->s[turn][room]] = data->next[pos.x];
				if (data->s[turn][room++] == data->end - 1)
					return (1);
			}
		}
	}
	if (realloc_next(data, turn))
		return (1);
	return (0);
}

void	pathfinding(t_data *data)
{
	int turn;

	turn = 0;
	if (!(data->s = ft_inttab(data->rooms, data->rooms)))
		ft_error(data, "Error malloc");
	if (!(data->way = (int *)ft_memalloc(sizeof(int) * ((unsigned long)data->rooms + 1))))
		ft_error(data, "Error malloc");
	if (!(data->next = (int *)ft_memalloc(sizeof(int) * ((unsigned long)data->rooms + 1))))
		ft_error(data, "Error malloc");
	ft_putinttab(data->way, data->rooms);
	ft_putinttab(data->next, data->rooms);
	ft_printf("data->rooms = %d\ndata->start = %d\ndata->end = %d\n", data->rooms, data->start, data->end);
	if (get_ways(data, turn))
		{
			get_best_way(data);
			return ;
		}
}
