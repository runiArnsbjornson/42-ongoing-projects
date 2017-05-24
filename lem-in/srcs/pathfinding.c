/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:43 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/24 16:18:59 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		realloc_next()
{
	free(data->next);
	if (!(data->next = (int*)ft_memalloc(sizeof(int) * (data->nb_rooms + 1))))
		return (1);
	data->a = -1;
	while (data->s[tour][++data->a])
		data->next[data->a] = data->s[tour][data->a];
	return (0);
}

int		search_room()
{
	int room;
	int i;

	room = 0;
	while (++room < data->rooms)
	{
		i = 0;
		while (++i < data->rooms)
			if (data->p[room][i] == stock * -1)
			{
				data->p[room][i] *= -1;
				return (room);
			}
	}
	return (0);
}

static int	shorten_best_way()
{
	int	i;
	int	search;

	i = 0;
	search = 0;
	if (!(data->best_way = (int*)ft_memalloc(sizeof(int) * data->len_tab)))
		return (1);
	while (data->affichage[i] != 0)
		i++;
	while (search < data->len_tab && data->affichage[--i] != 0)
		data->best_way[search++] = data->affichage[i];
	return (0);
}

int		get_best_way()
{
	int i;
	int search;

	i = 0;
	search = data->end - 1;
	if (!(data->display = (int *)ft_memalloc(sizeof(int) * (data->rooms + 1))))
		ft_error("Error malloc");
	while (search != - 1)
	{
		if (search != 0 && search != data->start - 1)
			data->display[i++] = search;
		search = data->way[search];
		if (search == 0)
		{
			data->affichage[i++] = data->start - 1;
			break ;
		}
	}
	data->len_tab = i;

}

int		get_ways(t_data *data, int turn)
{
	int room;
	t_pos pos;

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
					way[data->start - 1] = -1;
				way[data->s[turn][room]] = data->next[pos.x];
				if (data->s[turn][room++] == data->end - 1)
					return (1);
			}
		}
	}
	return (realloc_next())
}

void	pathfinding(t_data *data)
{
	t_pos	pos;
	int turn;

	turn = 0;
	if (!data->s = ft_inttab((size_t)data->rooms,(size_t)data->rooms) ||
		!(data->next = (int *)ft_memalloc(sizeof(int) * (data->rooms + 1))) ||
		!(data->way = (int *)ft_memalloc(sizeof(int) * (data->rooms + 1))))
		ft_error("Error malloc");
	data->next[0] = data->start - 1;
	while (data->next[0])
	{
		if (get_ways(data, turn++))
			get_best_way(data);
	}
}
