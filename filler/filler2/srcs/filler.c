/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:20:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/15 17:19:43 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		starting_pos(t_data *data, int *ref)
{
	t_pos	pos;
	int		start;

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

void	get_piece(t_data *data, int *ref, char *line)
{
	char *tmp;
	int i;

	i = 0;
	if (ref[2] == 0)
	{
		data->piece->y = ft_atoi(ft_strstr(line, " "));
		data->piece->x = ft_atoi(ft_strrchr(line, ' '));
		dprintf(2, "line=#%s# (%d) (%d)\n", line, data->piece->y, data->piece->x);
		if (ref[4] > 1)
		{
			ft_tabdel(data->piece->piece);
			ref[4] = 1;
		}
		if (!(data->piece->piece = malloc(sizeof(char *) * (data->piece->y + 1))))
			perror("Error malloc");
		data->piece->piece[data->piece->y] = NULL;
	}
	tmp = line;
	dprintf(2, "%s\n", tmp);
	if (ref[2] > 0 && ref[2] < data->piece->y + 1)
		data->piece->piece[ref[2] - 1] = ft_strdup(tmp);
	while (data->piece->piece[i])
	{
		dprintf(2, "p[%d]=[%s] %d %d\n", i, data->piece->piece[i], data->piece->y , data->piece->x);
		i++;
	}
	ref[2] += 1;
}

void	get_board(t_board *board, int *ref, char *line)
{
	if (ref[1] == 0)
	{
		board->y = ft_atoi(ft_strstr(line, " "));
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
		if (line == NULL)
			ft_put_error();
		board->board[ref[1] - 2] = ft_strdup(ft_strstr(line, " ") + 1);
	}
	ref[1] += 1;
}

void	parse(t_data *data, int *ref)
{
	char	*line;

	while (ft_gnl(0, &line))
	{
		if (!line)
			ft_put_error();
		dprintf(2, "line=<%s>\n", line);
		if (ref[0]++ == 0 && ft_strncmp("$$$ exec p", line, 10) == 0)
			data->player = line[10] == '1' ? 1 : 2;
		else if (ft_strncmp("Plateau", line, 7) == 0 || (ref[1] > 0 && ref[1] <= (data->board->y + 1)))
			get_board(data->board, ref, line);
		else if (ft_strncmp("Piece", line, 5) == 0 || (ref[2] > 0 && ref[2] <= data->piece->y))
		{
			get_piece(data, ref, line);
			strategy(data, ref);
		}
	}
}
