/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:26:45 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/02 13:54:49 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!(s1))
		return ((char *)s2);
	if (!(s2))
		return ((char *)s1);
	if ((ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = ft_strlen(s1);
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	return (ret);
}
