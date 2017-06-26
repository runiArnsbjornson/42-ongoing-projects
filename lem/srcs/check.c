/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 09:36:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/23 12:55:33 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	check_data(t_data *d)
{
	if (d->start == d->end || d->start < 0 || d->end < 0)
		ft_error(d, "Error with start/end");
	if (d->lmax == 0)
		ft_error(d, "Error with tube");
}

void	check_tube(t_data *d, t_list *tmp, char *r1, char *r2)
{
	t_pos check;

	check.x = 0;
	check.y = 0;
	while (tmp)
	{
		if (ft_strcmp(r1, tmp->content) == 0)
		{
			d->y = check.x;
			check.y++;
		}
		if (ft_strcmp(r2, tmp->content) == 0)
		{
			d->x = check.x;
			check.y++;
		}
		tmp = tmp->next;
		check.x++;
	}
	if (check.y != 2 || d->x == d->y)
		ft_error(d, "Error with tube");
}

void	check_coor(t_data *d, char *line)
{
	char *t;
	char *t1;

	if (!(ft_bool_strchr(line, ' ')))
	{
		ft_strdel(&line);
		ft_error(d, "Invalid room");
	}
	t = ft_strccpy(ft_strchr(line, ' ') + 1, ' ');
	t1 = ft_strrchr(line, ' ') + 1;
	if (t == NULL || t1 == NULL || ft_strcmp(t, "") == 0 ||
	ft_strcmp(t1, "") == 0 || ft_stris(t, ft_isdigit) == 0 ||
	ft_stris(t1, ft_isdigit) == 0 || ft_strtol(t) > INT_MAX ||
	ft_strtol(t1) > INT_MAX)
	{
		ft_strdel(&t);
		ft_error(d, "Invalid room coor");
	}
	ft_strdel(&t);
}

void	check_rooms(t_data *d, char *r1)
{
	t_list *tmp;

	if (*r1 == 'L' || *r1 == '#' || ft_bool_strchr(r1, '-'))
		ft_error(d, "Invalid room name");
	tmp = d->r;
	while (tmp)
	{
		if (ft_strcmp(r1, tmp->content) == 0)
			ft_error(d, "Duplicate room name");
		tmp = tmp->next;
	}
}

int		check_opt(const char c)
{
	const char	flag[6] = "drpsba";
	int			i;

	i = -1;
	while (++i < 6)
	{
		if (c == flag[i])
			return (1);
	}
	return (0);
}
