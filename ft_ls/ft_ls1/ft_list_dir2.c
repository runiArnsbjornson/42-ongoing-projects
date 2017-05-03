/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:14:06 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/30 15:11:57 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <dirent.h>
#include <stdio.h>
#include <errno.h>

char *ft_endless_strjoin(int nbr, ...);
int	dir_op(char *param, t_opt *o);

int	dir_depth(int n, char **pa, t_opt *o)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("\n%s:\n", pa[i]);
		dir_op(pa[i], o);
		i++;
	}
	return (0);
}

int	dir_read(DIR *dr, char *param, t_opt *o)
{
	struct dirent *dp;
	char *pa;
	char **tab;
	int n;

	n = 0;
	tab = malloc(sizeof(char *) * 16);
	while ((dp = readdir(dr)) != NULL)
	{
		if (dp->d_type == DT_DIR && dp->d_name[0] != '.')
		{
			pa = ft_endless_strjoin(3, param, "/", dp->d_name);
			tab[n] = malloc(sizeof(char) * ft_strlen(pa));
			tab[n] = pa;
			n++;
		}
		if (dp->d_type == 4)
		{
			if (o->all)
				printf(BOL "%s\n" RES, dp->d_name);
			else if (dp->d_name[0] != '.')
				printf(BOL "%s\n" RES, dp->d_name);
		}
		else
			printf("%s\n", dp->d_name);
	}
	if (n && o->rec)
		dir_depth(n, tab, o);
	closedir(dr);
	return (0);
}

int	dir_op(char *param, t_opt *o)
{
	DIR *dr;

	if (!(dr = opendir(param)))
		{
			ft_putstr_fd(ft_endless_strjoin(3, "ft_ls: ", param, ": "), 2);
			perror("");
			return(0);
		}
	dir_read(dr, param, o);
	return (0);
}

int	zero_struct(t_opt *o)
{
	o->lon = 0;
	o->rec = 0;
	o->all = 0;
	o->rev = 0;
	o->tim = 0;
	return (0);
}

int	option(char *param, t_opt *o)
{

	while (*param)
	{
		if (*param == 'R')
			o->rec = 1;
		if (*param == 'l')
			o->lon = 1;
		if (*param == 'r')
			o->rev = 1;
		if (*param == 't')
			o->tim = 1;
		if (*param == 'a')
			o->all = 1;
		param++;
	}
	return 0;
}

int	main(int ac, char **av)
{
	t_opt o;
	int i;
	int o_dr;

	zero_struct(&o);
	i = 1;
	o_dr = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			option(av[i], &o);
		else
		{
			o_dr++;
			dir_op(av[i], &o);
		}
		i++;
	}
	if (o_dr == 0)
		dir_op(".", &o);
	return (0);
}
