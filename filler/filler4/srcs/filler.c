/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:20:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/02 18:04:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init(t_data *data, int *ref)
{
	if (!data->piece)
	{
		if ((data->piece = malloc(sizeof(t_piece))) == 0)
			perror("Error malloc");
	}
	data->piece->x = -2;
	data->piece->y = -2;
	if (!data->board)
	{
		if ((data->board = malloc(sizeof(t_board))) == 0)
			perror("Error malloc");
	}
	data->board->x = -2;
	data->board->y = -2;
	ref[0] = 0;
	ref[1] = 0;
	ref[2] = 0;
	ref[3] += 1;
	ref[4] += 1;
}

void	strategy(t_data *data, int *ref)
{
	static int	swap = 0;
	static int	ini = 0;
	t_pos		start;

	if (ref[2] == (data->piece->y + 1))
	{
		if (ref[5] < 2)
		{
			if (ref[5] == 0)
			{
				start = where_am_i(data, ref);
				ini = start.x - start.y;
			}
			ini <= 0 ? block(data, ref) : block_p2(data, ref);
		}
		else
		{
			if (swap++ == 0)
				ini <= 0 ? search(data) : search_p2(data);
			else
			{
				ini <= 0 ? fill(data) : fill_p2(data);
				swap = 0;
			}
		}
		data->graph ? display_graph(data) : 0;
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
		data->piece->piece[data->piece->y] = 0;
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
		board->board[board->y] = 0;
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
