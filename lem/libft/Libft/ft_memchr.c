/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:24:22 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:01:00 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)(uintptr_t)s;
	while (n)
	{
		if (*(tmp_s)++ == ((unsigned char)c))
			return ((void *)(tmp_s - 1));
		n--;
	}
	return (NULL);
}
