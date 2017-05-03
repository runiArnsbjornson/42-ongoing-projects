/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:14:06 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/13 16:42:37 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_nstrjoin(int nbr, ...);
int		dir_op(char *param, t_opt *o);
int		long_display(char *av, t_opt *o);

void	display(t_dir *dp, char *name, t_opt *o)
{
	if (o->all)
	{
		if (o->lon)
			long_display(dp->d_name, o);
		else
			printf("%s\n", name);
	}
	else if (dp->d_name[0] != '.')
	{
		if (o->lon)
			long_display(dp->d_name, o);
		else
			printf("%s\n", name);
	}
}

int		dir_depth(int n, char **pa, t_opt *o)
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

int		dir_read(DIR *dr, char *param, t_opt *o)
{
	t_dir	*dp;
	char	*pa;
	char	**tab;
	int		n;

	n = 0;
	tab = malloc(sizeof(char *) * 16);
	while ((dp = readdir(dr)) != NULL)
	{
		if (dp->d_type == DT_DIR && dp->d_name[0] != '.')
		{
			pa = ft_nstrjoin(3, param, "/", dp->d_name);
			tab[n] = malloc(sizeof(char) * ft_strlen(pa));
			tab[n] = pa;
			n++;
		}
		dp->d_type == DT_FIFO ? display(dp, ft_nstrjoin(3, YEL, dp->d_name, RES), o) : 0;
		dp->d_type == DT_CHR ? display(dp, ft_nstrjoin(4, BLU, BYEL, dp->d_name, RES), o) : 0;
		dp->d_type == DT_DIR ? display(dp, ft_nstrjoin(3, BOLD, dp->d_name, RES), o) : 0;
		dp->d_type == DT_BLK ? display(dp, ft_nstrjoin(4, BLU, BCYA, dp->d_name, RES), o) : 0;
		dp->d_type == DT_REG ? display(dp, dp->d_name, o) : 0;
		dp->d_type == DT_LNK ? display(dp, ft_nstrjoin(3, MAG, dp->d_name, RES), o) : 0;
		dp->d_type == DT_SOCK ? display(dp, ft_nstrjoin(3, RED, dp->d_name, RES), o) : 0;
	}
	if (n && o->rec)
		dir_depth(n, tab, o);
	return (0);
}

int		dir_op(char *param, t_opt *o)
{
	DIR *dr;

	if (!(dr = opendir(param)))
	{
		ft_putstr_fd(ft_nstrjoin(3, "ft_ls: ", param, ": "), 2);
		perror("");
		return (0);
	}
	if (o->lon)
		long_display(param, o);
	else
		dir_read(dr, param, o);
	closedir(dr);
	return (0);
}

int		zero_struct(t_opt *o)
{
	o->lon = 0;
	o->rec = 0;
	o->all = 0;
	o->rev = 0;
	o->tim = 0;
	o->precise_time = 12;
	return (0);
}

int		option(char *param, t_opt *o)
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
		if (*param == 'T')
			o->precise_time = 20;
		param++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_opt	o;
	int		i;
	int		o_dr;

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
