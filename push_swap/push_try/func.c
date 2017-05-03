/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:21:19 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/23 16:29:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push(t_lst **p, int value)
{
	t_lst *node;

	node = malloc(sizeof(t_lst));
	if (node == NULL)
		return (NULL);
	node->x = value;
	node->prec = *p;
	*p = node;
}

void	del(t_lst **p)
{
	t_lst *node;

	while (*p)
	{
		tmp = (*p)->prec;
		free(*p);
		*p = tmp;
	}
}

int		lst_size(t_lst *p)
{
	int size;

	size = 0;
	while (p)
	{
		++size;
		p = p->prec;
	}
	return (size);
}
