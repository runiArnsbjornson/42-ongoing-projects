/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:44:36 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/10 16:39:08 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_memcpy(dst, src, p - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
