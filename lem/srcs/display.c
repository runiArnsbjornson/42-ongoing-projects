/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:04:23 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/21 12:38:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	display_solution(t_data *d)
{
	int in;
	int x;

	if (d->best == NULL || d->best[0] == d->best[1])
		ft_error(d, "No solution");
	if (d->max == NULL)
		if (!(d->max = ft_memalloc(sizeof(int) * (unsigned long)(d->ants + 1))))
			ft_error(d, "Error malloc");
	in = 1;
	while (d->max[d->ants] != d->len)
	{
		x = 0;
		while (++x < in)
		{
			if (d->max[x] != d->len)
			{
				d->max[x] += 1;
				ft_printf("L%d-%s ", x, get_content(d->r, d->best[d->max[x]]));
			}
		}
		ft_printf("\n");
		if (in <= d->ants)
			in++;
	}
}

void	display_rooms(t_data *d, t_list *tmp, int i)
{
	ft_printf(GRN "List of rooms :\n" RES);
	while (tmp)
	{
		ft_printf("%d : %s", i, tmp->content);
		if (i == d->start - 1)
			ft_printf(" << entrance\n");
		else if (i == d->end - 1)
			ft_printf(" << exit\n");
		else
			ft_printf("\n");
		tmp = tmp->next;
		i++;
	}
}

void	display_data(t_data *d, t_list *tmp, int i)
{
	ft_printf(BLU "Data parsed\n" RES);
	ft_printf("There are %d rooms and %d paths\n", d->rooms, (d->lmax - 1) / 2);
	while (tmp && i < d->start - 1)
	{
		tmp = tmp->next;
		i++;
	}
	ft_printf("%d ant%swill go inside\n", d->ants, d->ants == 1 ? " " : "s ");
	ft_printf("starting room is : %s\n", tmp->content);
	tmp = d->r;
	i = -1;
	while (tmp && ++i < d->end - 1)
		tmp = tmp->next;
	ft_printf("exit is in room : %s\n", tmp->content);
}

void	display_best(t_data *d)
{
	int i;

	if (d->best == NULL || (d->best[0] == d->best[1]))
	{
		ft_put_error("No solution");
		return ;
	}
	i = -1;
	while (++i < d->len + 1)
	{
		if (i == 0)
			ft_printf(CYA "Best solution :\n" RES);
		ft_printf("%s%s", get_content(d->r, d->best[i]),
		i == d->len ? "\n" : " -> ");
	}
	ft_printf("\nThis way has %d tube%s", d->len, d->len == 1 ? "\n" : "s\n");
}

void	display(t_data *d, int type)
{
	t_list	*tmp;

	tmp = d->r;
	if (!!(type & (DATA << 0)) || (!!(type & (ALL << 0))))
		display_data(d, tmp, 0);
	if (!!(type & (ROOM << 0)) || (!!(type & (ALL << 0))))
		display_rooms(d, tmp, 0);
	if (!!(type & (PATH << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(MAG "Matrix of paths :\n" RES);
		ft_putinttab(d->t, d->rooms);
	}
	if (!!(type & (SOLV << 0)) || (!!(type & (ALL << 0))))
	{
		ft_printf(YEL "Matrix of solution(s) :\n" RES);
		ft_putinttab(d->s, d->lmax);
	}
	if (!!(type & (BEST << 0)) || (!!(type & (ALL << 0))))
		display_best(d);
}
