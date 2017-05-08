/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:54:37 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/10 15:06:02 by jdebladi         ###   ########.fr       */
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
		return ((char *)big);
	ret = (char *)big;
	while (big[i])
	{
		j = 0;
		while (big[i] == little[j] && big[i])
		{
			if (j == ft_strlen((char *)little) - 1)
				return (&ret[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
