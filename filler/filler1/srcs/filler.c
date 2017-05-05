/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:20:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/05 16:56:54 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		starting_pos(t_data *data, int *ref)
{
	t_pos pos;
	int start;

	start = 1;
	pos.y = 0;
	while (pos.y < data->board->y)
	{
		pos.x = 0;
		while (pos.x < data->board->x)
		{
			if (data->board->board[pos.y][pos.x] == data->player)
			{
				ref[5] = 1;
				start = pos.x < data->board->x / 2 ? 1 : 2;
				return (start);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

void	strategy(t_data *data, int *ref)
{
	static int swap = 0;
	static int start = 0;

	if (ref[2] == (data->piece->y + 1))
	{
		if (ref[5] == 0)
			start = starting_pos(data, ref);
		if (ref[5] == 1)
			start == 1 ? block(data, ref) : block_p2(data, ref);
		else if (ref[5] == 2)
			start == 1 ? block_2(data, ref) : block_p2_2(data, ref);
		else
		{
			if (swap++ == 0)
				start == 1 ? search(data) : search_p2(data);
			else
			{
				start == 1 ? fill(data) : fill_p2(data);
				swap = 0;
			}
		}
		data->graph == 1 ? display_graph(data) : 0;
		init(data, ref);
	}
}

void	get_piece(t_data *data, int *ref, char **res)
{
	if (ref[2] == 0)
	{
		data->piece->y = ft_atoi(res[1]);
		res[2][ft_strlen(res[2]) - 1] = 0;
		data->piece->x = ft_atoi(res[2]);
		if (ref[4] > 1)
		{
			ft_tabdel(data->piece->piece);
			ref[4] = 1;
		}
		if (!(data->piece->piece = malloc(sizeof(char *) *
		(data->piece->y + 1))))
			perror("Error malloc");
		data->piece->piece[data->piece->y] = NULL;
	}
	ref[2] > 0 ? data->piece->piece[ref[2] - 1] = ft_strdup(res[0]) : 0;
	ref[2] += 1;
	strategy(data, ref);
}

void	get_board(t_board *board, int *ref, char **res)
{
	if (ref[1] == 0)
	{
		board->y = ft_atoi(res[1]);
		res[2][ft_strlen(res[2]) - 1] = 0;
		board->x = ft_atoi(res[2]);
		if (ref[3] > 1)
		{
			ft_tabdel(board->board);
			ref[3] = 1;
		}
		if (!(board->board = malloc(sizeof(char *) * (board->y + 1))))
			perror("Error malloc");
		board->board[board->y] = NULL;
	}
	if (ref[1] > 1)
		board->board[ref[1] - 2] = ft_strdup(res[1]);
	ref[1] += 1;
}

void	parse(t_data *data, int *ref)
{
	char *line;
	char **res;

	while (get_next_line(0, &line))
	{
		res = ft_strsplit(line, ' ');
		if (ref[0] == 0 && ft_strcmp(res[0], "$$$") == 0)
		{
			data->player = (ft_atoi(++res[2]) == 1) ? P1 : P2;
			ref[0] += 1;
		}
		else if (ft_strcmp(res[0], "Plateau") == 0 ||
		ref[1] < (data->board->y + 2))
			get_board(data->board, ref, res);
		else if (ft_strcmp(res[0], "Piece") == 0 ||
		ref[2] < (data->piece->y + 2))
			get_piece(data, ref, res);
	}
}
