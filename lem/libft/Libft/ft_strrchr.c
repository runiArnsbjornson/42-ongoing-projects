/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:18:24 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:53:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = ft_strlen((char *)(uintptr_t)s) + 1;
	tmp = (char *)(uintptr_t)s;
	while (i-- != 0)
	{
		if ((unsigned char)c == tmp[i])
			return (&tmp[i]);
	}
	return (NULL);
}
