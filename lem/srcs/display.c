/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:04:23 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/16 13:38:22 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

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
	ft_printf("%d ant%s in the anthill\n", d->ants, d->ants == 1 ? " is" : "s are");
	ft_printf("starting room is : %s\n", tmp->content);
	tmp = d->r;
	i = -1;
	while (tmp && ++i < d->end - 1)
		tmp = tmp->next;
	ft_printf("exit is in room : %s\n", tmp->content);
}

void	display_best(t_data *d, t_list *tmp, int i)
{
	int j;

	if (d->best == NULL || (d->best[0] == d->best[1]))
		ft_error(d, "No solution found");
	while (++i < d->len + 1)
	{
		i == 0 ? ft_printf(BOL CYA "Best solution :\n" RES) : 0;
		i == 0 ? ft_printf("shortest way is %d long\n", d->len + 1): 0;
		j = d->best[i];
		while (tmp && j--)
			tmp = tmp->next;
		ft_printf("%s%s", tmp->content, i == d->len ? "\n" : " -> ");
		tmp = d->r;
	}
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
		display_best(d, tmp, -1);
}
