/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:54:37 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:55:41 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	if (!little[i])
		return ((char *)(uintptr_t)big);
	ret = (char *)(uintptr_t)big;
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && big[i])
		{
			if (j == ft_strlen((char *)(uintptr_t)little) - 1)
				return (&ret[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
