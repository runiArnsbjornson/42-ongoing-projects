/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:58:57 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/10 13:57:33 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] && tmp[i] != c)
		i++;
	if (tmp[i] == c)
		return (&tmp[i]);
	else
		return (NULL);
}
