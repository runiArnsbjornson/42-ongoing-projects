/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnbytelen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:42:27 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/12 14:24:08 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcsnbytelen(const wchar_t *s, size_t n)
{
	const wchar_t	*p;
	size_t			byte_size;

	p = s;
	byte_size = 0;
	if (n == 0)
		return (0);
	while (*p)
	{
		byte_size += ft_wcbytesize(*p);
		if (byte_size > n)
		{
			byte_size -= ft_wcbytesize(*p);
			break ;
		}
		++p;
	}
	return (byte_size);
}
