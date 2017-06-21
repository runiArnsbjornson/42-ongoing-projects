/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:50:24 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/21 14:28:50 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	shortening_best(t_data *d)
{
	t_pos	pos;
	t_pos	cmp;

	pos.x = -1;
	while (++pos.x < d->lmax + d->rooms && d->best != NULL)
	{
		pos.y = -1;
		while(++pos.y < d->lmax)
		{
			cmp.x = pos.y;
			while (++cmp.x < d->lmax)
			{
				if (d->s[pos.x][pos.y] == d->best[cmp.x] && d->best[cmp.x] != -1)
				{
					cmp.y = -1;
					while (++cmp.y < pos.y)
						d->best[cmp.y] = d->s[pos.x][cmp.y];
					while (d->best[cmp.x - 1] != -1)
						d->best[cmp.y++] = d->best[cmp.x++];
					d->len = cmp.y - 2;
				}
			}
		}
	}
}

char	*get_content(t_list *t, int index)
{
	if (index > ft_lstlen(&t) || t == NULL)
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
