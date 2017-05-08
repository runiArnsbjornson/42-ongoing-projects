/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:52:55 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/02 17:58:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/Libft/libft.h"
# include <stdio.h>
# include <errno.h>

# define P1 'O'
# define P2 'X'

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
	float	p2;
	float	p1;
	float	wht;
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
t_pos			where_am_i(t_data *data, int *ref);
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
void			init(t_data *data, int *ref);
void			strategy(t_data *data, int *ref);
void			get_piece(t_data *data, int *ref, char **res);
void			get_board(t_board *board, int *ref, char **res);
void			parse(t_data *data, int *ref);
/*
** search.c
*/
int				find(t_data *data, t_pos pos);
int				search_p2(t_data *data);
int				search(t_data *data);
int				fill_p2(t_data *data);
int				fill(t_data *data);

#endif