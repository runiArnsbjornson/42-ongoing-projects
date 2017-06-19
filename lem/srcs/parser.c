/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 10:54:32 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 16:53:04 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	get_tube(t_data *d, char *line)
{
	char		*r1;
	t_list		*tmp;

	r1 = ft_strccpy(line, '-');
	if (d->p == NULL)
		if (!(d->p = ft_inttab(d->rooms, d->rooms)) ||
		!(d->t = ft_inttab(d->rooms, d->rooms)))
			ft_error(d, "Error malloc");
	tmp = d->r;
	check_tube(d, tmp, r1, ft_strchr(line, '-') + 1);
	d->t[d->y][d->x] = 1;
	d->t[d->x][d->y] = 1;
	d->p[d->y][d->x] = 1;
	d->p[d->x][d->y] = 1;
	d->lmax++;
	ft_strdel(&r1);
}

void	get_room(t_data *d, char *line)
{
	char	*r;
	char	*t;
	t_list	*tmp;

	r = ft_strccpy(line, 32);
	check_rooms(d, r);
	if ((tmp = ft_lstnew(r, ft_strlen(r))) == NULL)
		ft_error(d, "Error malloc");
	ft_lstaddend(&d->r, tmp);
	d->rooms++;
	t = ft_strccpy(ft_strchr(line, ' ') + 1, ' ');
	if (ft_strrchr(line, ' ') + 1 == NULL || t == NULL ||
		ft_stris(t, ft_isdigit) == 0 ||
		ft_stris(ft_strrchr(line, ' ') + 1, ft_isdigit) == 0)
	{
		ft_strdel(&t);
		ft_strdel(&r);
		ft_error(d, "Invalid room coor");
	}
	if (d->start == 0)
		d->start = d->rooms;
	if (d->end == 0)
		d->end = d->rooms;
	ft_strdel(&t);
	ft_strdel(&r);
}

void	get_type(t_data *d, char *line, int fd)
{
	if (ft_strcmp(line, "##start") == 0 && d->start == -1)
	{
		if (gnl(fd, &line) > 0)
		{
			d->start = 0;
			get_room(d, line);
			ft_strdel(&line);
		}
	}
	else if (ft_strcmp(line, "##end") == 0 && d->end == -1)
	{
		if (gnl(fd, &line) > 0)
		{
			d->end = 0;
			get_room(d, line);
			ft_strdel(&line);
		}
	}
	else if (ft_strcmp(line, "##end") == 0 || ft_strcmp(line, "##start") == 0)
		ft_error(d, "Redefinition of start/end");
}

void	get_ants_nbr(t_data *d, int fd)
{
	char	*line;

	if (gnl(fd, &line) > 0)
	{
		if (!*line)
			ft_error(d, "Invalid ants input");
		d->ants = ft_atoi(line);
		ft_strdel(&line);
	}
	if (!(d->ants > 0 && d->ants <= INT_MAX))
		ft_error(d, "Wrong ants number");
}

void	parser(t_data *d, char *av)
{
	char	*line;
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error(d, "Read failed");
	get_ants_nbr(d, fd);
	while (gnl(fd, &line) > 0)
	{
		if (!*line)
			break ;
		if (ft_strncmp(line, "##", 2) == 0)
			get_type(d, line, fd);
		else if (*line == '#')
			ft_putendl(line + 1);
		else
		{
			if (!(ft_bool_strchr(line, ' ')) && !(ft_bool_strchr(line, '-')))
				ft_error(d, "Wrong input");
			if (ft_bool_strchr(line, ' '))
				get_room(d, line);
			if (ft_bool_strchr(line, '-'))
				get_tube(d, line);
		}
		ft_strdel(&line);
	}
}
