/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 11:36:17 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/30 15:48:58 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	t_list *tmp;
	t_list *next;

	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		if (tmp->content != NULL)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
