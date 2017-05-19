/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 09:55:33 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/18 12:44:25 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(const char *src, int c)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	if (!src)
		return (ret);
	if (c != 0)
	{
		i = 0;
		while (src[i] != (unsigned char)c)
			i++;
		if (!(ret = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		j = 0;
		while (j < i)
		{
			ret[j] = src[j];
			j++;
		}
		ret[j] = 0;
	}
	return (ret);
}