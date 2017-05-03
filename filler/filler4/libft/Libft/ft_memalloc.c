/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:13:00 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/09 12:50:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ret;

	if (size == 0)
		return (NULL);
	if ((ret = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}
