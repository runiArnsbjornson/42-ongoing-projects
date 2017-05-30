/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:13:00 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/30 17:48:52 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ret;

	if (size == 0)
		return (NULL);
	if (!(ret = malloc(size)))
		return (NULL);
	while (size)
		((char *)ret)[size--] = 0;
	return ((void *)ret);
}
