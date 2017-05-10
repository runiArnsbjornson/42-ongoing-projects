/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:02:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/10 18:12:11 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <errno.h>

# define MERROR perror("Error malloc");
# define ERR ft_putendl_fd("ERROR", 2);

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_path
{
	int		r1;
	int		r2;
}				t_path;

typedef struct	s_room
{
	char	*name;
	int		type;
	int		ant;
	t_pos	pos;
}				t_room;

typedef struct	s_data
{
	t_list	*room;
	t_list	*b;
	t_list	*c;
	int		ants;
	int		paths;
}				t_data;