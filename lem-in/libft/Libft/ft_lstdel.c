/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:37:43 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/14 16:44:35 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	while (*alst && del)
	{
		tmp = (*alst)->next;
		if (*alst && del)
		{
			(del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
		*alst = tmp;
	}
	*alst = NULL;
}
