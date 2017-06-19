/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:50:24 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 11:25:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char	*get_content(t_list *t, int index)
{
	if (index > ft_lstlen(&t))
		return (NULL);
	while (t && index--)
		t = t->next;
	return (t->content);
}

void	get_best(t_data *d)
{
	t_pos pos;

	pos.x = -1;
	while (++pos.x < d->lmax + d->rooms)
	{
		pos.y = -1;
		while (++pos.y < d->lmax)
		{
			if (d->s[pos.x][0] == d->start - 1 && pos.y < d->len
				&& d->s[pos.x][pos.y] == d->end - 1)
			{
				d->best = d->s[pos.x];
				d->len = pos.y;
				break ;
			}
		}
	}
}

void	ft_setinttab(int **tab, int col, int n)
{
	int x;
	int y;

	y = -1;
	while (tab[++y] != NULL)
	{
		x = -1;
		while (++x < col)
			tab[y][x] = n;
	}
}
