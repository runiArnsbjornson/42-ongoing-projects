/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:12:50 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 13:02:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dtmp;
	const char	*stmp;

	dtmp = dst;
	stmp = src;
	while (n--)
		*dtmp++ = *stmp++;
	return (dst);
}
