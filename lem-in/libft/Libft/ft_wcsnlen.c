/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:39:06 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:05:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcsnlen(const wchar_t *s, size_t n)
{
	const wchar_t	*p;
	int				byte_size;

	p = s;
	byte_size = ft_wcbytesize(*p);
	while (*p && byte_size <= (int)n)
	{
		byte_size += ft_wcbytesize(*p);
		++p;
	}
	return ((int)(p - s));
}
