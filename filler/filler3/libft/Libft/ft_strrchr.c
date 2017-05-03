/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:18:24 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/14 18:21:05 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = ft_strlen((char *)s) + 1;
	tmp = (char *)s;
	while (i-- != 0)
	{
		if ((unsigned char)c == tmp[i])
			return (&tmp[i]);
	}
	return (NULL);
}
