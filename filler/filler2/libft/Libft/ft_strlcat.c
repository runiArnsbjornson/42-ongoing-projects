/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:22:57 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/10 16:00:16 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		n;
	size_t		dlen;

	tmp_dst = dst;
	tmp_src = src;
	n = size;
	while (*tmp_dst && n-- != 0)
		tmp_dst++;
	dlen = tmp_dst - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(tmp_src));
	while (*tmp_src)
	{
		if (n != 1)
		{
			*tmp_dst++ = *tmp_src;
			n--;
		}
		tmp_src++;
	}
	*tmp_dst = '\0';
	return (dlen + (tmp_src - src));
}
