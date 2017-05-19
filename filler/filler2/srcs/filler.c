/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:20:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/17 14:28:47 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		starting_pos(t_data *data, int *ref)
{
	t_pos	pos;
	int		start;

	start = 0;
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
	ref[5] = 1;
	return (3);
}

void	strategy(t_data *data, int *ref)
{
	static int swap = 0;
	static int start = 0;

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

void	get_piece(t_data *data, t_piece *piece, int *ref, char *line)
{
	if (ref[2] == 0)
	{
		piece->y = ft_atoi(ft_strchr(line, ' '));
		piece->x = ft_atoi(ft_strrchr(line, ' '));
		if (ref[4] > 1)
		{
			ft_tabdel(piece->piece);
			ref[4] = 1;
		}
		if (!(piece->piece = malloc(sizeof(char *) * (piece->y + 1))))
			perror("Error malloc");
		piece->piece[piece->y] = NULL;
	}
	if (ref[2] > 0 && ref[2] < piece->y + 1)
	{
		if (line == NULL)
			ft_error(data, 0);
		piece->piece[ref[2] - 1] = ft_strdup(line);
	}
	ref[2] += 1;
}

void	get_board(t_data *data, t_board *board, int *ref, char *line)
{
	if (ref[1] == 0)
	{
		board->y = ft_atoi(ft_strchr(line, ' '));
		board->x = ft_atoi(ft_strrchr(line, ' '));
		if (ref[3] > 1)
		{
			ft_tabdel(board->board);
			ref[3] = 1;
		}
		if (!(board->board = malloc(sizeof(char *) * (board->y + 1))))
			perror("Error malloc");
		board->board[board->y] = NULL;
	}
	if (ref[1] > 1 && ref[1] < board->y + 2)
	{
		if (line == NULL || (ft_strchr(line, ' ') + 1) == NULL)
			ft_error(data, 0);
		board->board[ref[1] - 2] = ft_strdup(ft_strchr(line, ' ') + 1 );
	}
	ref[1] += 1;
}

void	parse(t_data *data, int *ref)
{
	char	*line;

	while (ft_gnl(0, &line))
	{
		if (!line)
			ft_error(data, "Bad player info");
		if (ft_strncmp("$$$ exec p", line, 9) == 0 && ref[0]++ == 0)
		{
			if (line[10] == '1' || line[10] == '2')
				data->player = line[10] == '1' ? 'O' : 'X';
			else
				ft_error(data, "Bad player info");
		}
		else if (data->player && (ft_strncmp("Plateau", line, 7) == 0 ||
		 ref[1] < data->board->y + 2))
			get_board(data, data->board, ref, line);
		else if (data->player && (ft_strncmp("Piece", line, 5) == 0 ||
		 ref[2] < data->piece->y + 2))
		{
		get_piece(data, data->piece, ref, line);
		ref[2] == data->piece->y + 1? strategy(data, ref) : 0;
		}
		else
			ft_error(data, "bad player info");
	}
}
