/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:02:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/16 12:20:36 by jdebladi         ###   ########.fr       */
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

typedef struct	s_room
{
	char	*name;
	long	type;
	t_pos	coor;
}				t_room;

typedef struct	s_data
{
	t_list	*r;
	t_list	*sol;
	int		**p;
	int		**s;
	int		**t;
	int		*best;
	int		*mark;
	int		graph;
	int		start;
	int		end;
	int		ants;
	int		rooms;
	int		lmax;
	int		x;
	int		y;
}				t_data;
/*
** main.c
*/
void			ft_free(t_data *data);
void			init_data(t_data *data);
void			bad_arg(void) __attribute__((noreturn));
void			graph_opt(char *av, t_data *d);
/*
** parser.c
*/
void			get_tube(t_data *data, char *line);
void			get_room(t_data *data, char *line);
void			get_type(t_data *data, char *line, int fd);
void			get_ants_nbr(t_data *data, int av);
void			parser(t_data *data, char *av);
/*
** utils.c
*/
void			check_data(t_data *d);
void			check_tube(t_data *data, t_list *tmp, char *r1, char *r2);
void			check_rooms(t_data *data, char *r);
int				check_opt(const char c);
void			ft_error(t_data *data, char *str) __attribute__((noreturn));
/*
** display.c
*/
void			display_rooms(t_data *data, t_list *tmp, int i);
void			display_data(t_data *data, t_list *tmp, int i);
void			display_best(t_data *data, t_list *tmp, int i);
void			display(t_data *data, int type);

#endif
