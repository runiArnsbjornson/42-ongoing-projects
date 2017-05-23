/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:34:25 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/23 10:50:39 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	size_t	i;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = malloc(content_size + 1);
		i = 0;
		while (i <= content_size)
		{
			((char *)(new->content))[i] = ((char *)(uintptr_t)content)[i];
			i++;
		}
		((char *)(new->content))[i] = '\0';
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
