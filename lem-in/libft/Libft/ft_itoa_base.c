/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:42:07 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 12:48:35 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long n, int base)
{
	char	buf[64];
	char	*ret;
	int		i;
	int		neg;

	i = 64;
	buf[--i] = 0;
	if (n == 0)
		buf[--i] = '0';
	neg = n < 0 ? 1 : 0;
	n = n < 0 ? n : -n;
	while (n)
	{
		if (-(n % base) >= 10)
			buf[--i] = (char)(-(n % base) + '7');
		else
			buf[--i] = (char)(-(n % base) + '0');
		n /= base;
	}
	if (neg && base == 10)
		buf[--i] = '-';
	ret = ft_strdup(&buf[i]);
	return (ret);
}
