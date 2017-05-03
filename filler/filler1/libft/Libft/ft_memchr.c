/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:24:22 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/09 13:55:07 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	while (n)
	{
		if (*(tmp_s)++ == ((unsigned char)c))
			return ((void *)(tmp_s - 1));
		n--;
	}
	return (NULL);
}
