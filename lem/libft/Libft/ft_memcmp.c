/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:26:29 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:01:26 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *)(uintptr_t)s1;
	tmp_s2 = (unsigned char *)(uintptr_t)s2;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i] && i < n)
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}
