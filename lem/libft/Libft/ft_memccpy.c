/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:44:36 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/30 16:44:57 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		tc;
	unsigned char		*tdst;
	const unsigned char	*tsrc;

	if (n)
	{
		tdst = dst;
		tsrc = src;
		tc = (unsigned char)c;
		while (n)
		{
			if ((*tdst++ = *tsrc++) == tc)
				return (tdst);
			n--;
		}
	}
	return (NULL);
}
