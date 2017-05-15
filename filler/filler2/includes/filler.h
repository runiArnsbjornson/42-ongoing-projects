/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:52:55 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/15 15:53:54 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdio.h>
# include <errno.h>

# define P1 'O'
# define P2 'X'
# define GRAPH 0

typedef struct	s_board
{
	int		x;
	int		y;
	char	**board;
}				t_board;

typedef struct	s_piece
{
	int		x;
	int		y;
	char	**piece;
}				t_piece;

typedef struct	s_data
{
	char	player;
	int		graph;
	t_board	*board;
	t_piece	*piece;
}				t_data;

typedef struct	s_display
{
	float	red;
	float	grn;
	float	wht;
	int		piece;
}				t_display;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

/*
** block.c
*/
void			block_p2(t_data *data, int *ref);
void			block(t_data *data, int *ref);
void			block_p2_2(t_data *data, int *ref);
void			block_2(t_data *data, int *ref);
/*
** display.c
*/
void			init_display(t_display *color);
void			display_percent(t_data *data, t_display *color);
void			display_color(t_data *data, t_pos *pos, t_display *color);
void			display_graph(t_data *data);
/*
** filler.c
*/
int				starting_pos(t_data *data, int *ref);
void			strategy(t_data *data, int *ref);
void			get_piece(t_data *data, int *ref, char *line);
void			get_board(t_board *board, int *ref, char *line);
void			parse(t_data *data, int *ref);
/*
** main.c
*/
void			init(t_data *data, int *ref);
/*
** search.c
*/
int				find(t_data *data, t_pos pos);
int				search_p2(t_data *data);
int				search(t_data *data);
int				fill_p2(t_data *data);
int				fill(t_data *data);

#endif
