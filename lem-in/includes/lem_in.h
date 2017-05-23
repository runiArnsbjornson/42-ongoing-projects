/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:02:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/23 17:00:31 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_path
{
	char		*r1;
	char		*r2;
}				t_path;

typedef struct	s_data
{
	t_list	*r;
	int		start;
	int		end;
	int		ants;
	int		rooms;
	int		x;
	int		y;
	int		**paths;
}				t_data;

void	ft_free(t_data *data);
void	display(t_data *data, int type);
void	ft_error(t_data *data, char *str) __attribute__ ((noreturn));
void	get_ants_nbr(t_data *data);
void	get_path(t_data *data, char *line);
void	get_room(t_data *data, char *line);
void	clean_type(t_data *data);
void	parser(t_data *data);
void	init_data(t_data *data);
void	get_type(t_data *data, char *line);
void	check_path(t_data *data, t_list *tmp, char *r1, char *r2);
void	check_data(t_data *data);
void	display_matrix(t_data *data, int i);
void	display_rooms(t_data *data, t_list *tmp, int i);
void	display_data(t_data *data, t_list *tmp, int i);
int		graph_opt(char *av);
void	pathfinding(t_data *data);

#endif
