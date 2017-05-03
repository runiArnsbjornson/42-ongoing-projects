/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:18:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/01 17:18:25 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcscmp(const wchar_t *s1, const wchar_t *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == 0)
			return (0);
	}
	return (*(const unsigned int *)s1 - *(const unsigned int *)--s2);
}
