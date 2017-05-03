/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:40:38 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/14 18:44:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy;

	cpy = (t_list *)malloc(sizeof(t_list *));
	if (!cpy || !lst)
		return (NULL);
	cpy = f(lst);
	cpy->next = ft_lstmap(lst->next, f);
	return (cpy);
}
