/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:37:55 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/14 15:07:06 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_enqueue(t_queue *q, int new)
{
	t_q *tmp;
	t_q *current;

	if (!(tmp = malloc(sizeof(*tmp))) || q == NULL)
	{
		ft_put_error("Error ft_enqueue");
		exit(0);
	}
	tmp->n = new;
	tmp->next = NULL;
	if (q->first != NULL)
	{
		current = q->first;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
	}
	else
		q->first = tmp;
}
