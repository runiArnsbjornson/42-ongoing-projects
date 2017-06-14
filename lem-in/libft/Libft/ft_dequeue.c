/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:34:33 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/14 15:07:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dequeue(t_queue *q)
{
	int		ret;
	t_q		*tmp;

	if (q == NULL)
		exit(EXIT_FAILURE);
	ret = 0;
	if (q->first != NULL)
	{
		tmp = q->first;
		ret = (int)tmp->n;
		q->first = tmp->next;
		free(tmp);
	}
	return (ret);
}
