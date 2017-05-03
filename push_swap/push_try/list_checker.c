/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:03:45 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/23 16:37:39 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

t_lst	*add_end(t_lst *head, int value)
{
	t_lst *new;
	t_lst *p;

	new = malloc(sizeof(t_lst));
	if (new != NULL)
	{
		new->x = value;
		new->next = NULL;
		if (head == NULL)
			head = new;
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = new;
		}
	}
	return (head);
}

void	del(t_lst **p)
{
	t_lst *node;

	while (*p)
	{
		node = (*p)->prec;
		free(*p);
		*p = node;
	}
}

void	push(t_lst **p, int value)
{
	t_lst *node;

	node = malloc(sizeof(t_lst));
	if (node == NULL)
		exit(EXIT_FAILURE);
	node->x = value;
	node->prec = *p;
	*p = node;
}

void	display(t_lst *head)
{
	t_lst *p;

	p = head;
	while (p != NULL)
	{
		printf("%d > ", p->x);
		p = p->prec;
	}
	printf("NULL\n");
}

int		main(int ac, char const **av)
{
	int		i;
	t_lst	*a;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		push(&a, ft_atoi(av[i]));
		++i;
	}
	display(a);
	del(&a);
	return (0);
}
