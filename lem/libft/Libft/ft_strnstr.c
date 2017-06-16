/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:32:40 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:52:43 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	if (!little[i])
		return ((char *)(uintptr_t)big);
	ret = (char *)(uintptr_t)big;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] == little[j] && big[i] && i < len)
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
