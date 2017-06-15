/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:02:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/15 14:14:12 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# define DATA 00000001
# define ROOM 00000010
# define PATH 00000100
# define SOLV 00001000
# define BEST 00010000
# define ALL 00100000

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_path
{
	char	*r1;
	char	*r2;
}				t_path;

typedef struct	s_stack
{
	t_list	*r;
	t_list	*sol;
	int		**p;
	int		**s;
	int		**t;
	int		*best;
	int		*mark;
	int		start;
	int		end;
	int		ants;
	int		rooms;
	int		lmax;
	int		len;
	int		x;
	int		y;
}				t_data;
/*
** main.c
*/
void			display_rooms(t_data *data, t_list *tmp, int i);
void			display_data(t_data *data, t_list *tmp, int i);
void			display_best(t_data *data, t_list *tmp, int i);
void			display(t_data *data, int type);
void			ft_free(t_data *data);
void			ft_error(t_data *data, char *str) __attribute__((noreturn));
void			get_ants_nbr(t_data *data, int av);
void			check_path(t_data *data, t_list *tmp, char *r1, char *r2);
void			get_path(t_data *data, char *line);
void			check_rooms(t_data *data, char *r);
void			get_room(t_data *data, char *line);
void			get_type(t_data *data, char *line, int fd);
void			parser(t_data *data, char *av);
void			init_data(t_data *data);
void			check_data(t_data *data);
int				check_opt(const char c);
void			bad_arg(void) __attribute__((noreturn));
int				graph_opt(char *av, int graph);
/*
** pathfinding.c
*/
void			display_solution(t_data *data);
void			display_queue(t_queue *f);
void			shortening_best_way(t_data *data);
void			get_best_way(t_data *data);
void			reset_matrix(t_data *data, int room, int turn, int try);
void			reset_hacked_matrix(t_data *data, int room, int turn, int try);
int				hacking_way(t_data *data, int room, int turn, int try);
int				get_ways(t_data *data, int room, int turn, int try);
void			set(t_data *data);
void			pathfinding(t_data *data);

#endif
