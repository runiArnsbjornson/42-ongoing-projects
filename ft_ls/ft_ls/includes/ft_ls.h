/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 20:32:54 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/20 12:13:44 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "Libft.h"
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <grp.h>
# include <dirent.h>

typedef struct 	dirent t_dir;

typedef struct	s_opt
{
	int	lon;
	int rec;
	int all;
	int rev;
	int tim;
	int precise_time;
}				t_opt;

typedef struct	s_stats
{
	unsigned long 	block;
	struct stat		*fs;
	struct passwd	*uid;
	struct group	*gid;
	char			*ti;
	char			*mode;
	char			*path;
}				t_stats;

typedef struct	s_lst
{
	char			*p;
	struct s_lst	*prec;
	struct s_lst	*next;
}				t_lst;

#endif
