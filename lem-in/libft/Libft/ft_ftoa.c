/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:47:02 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:12:15 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ftoa_mantis(char *buf, long long carac, long double n, int p)
{
	int			i;
	int			j;
	int			digit;
	long double	mantis;
	long double	approx;

	j = 0;
	i = 63;
	mantis = n - (long double)carac;
	approx = -mantis * ft_pwr(10, p + 1);
	mantis = -mantis * ft_pwr(10, p);
	digit = (int)mantis;
	approx = approx - digit * 10;
	digit += (int)approx >= 5 ? 1 : 0;
	while (j++ < p)
	{
		buf[--i] = digit % 10 + '0';
		digit /= 10;
	}
	buf[--i] = '.';
	return (i);
}

char			*ft_ftoa(long double n, int precision)
{
	char		buf[64];
	char		*ret;
	int			i;
	int			neg;
	long long	carac;

	i = 64;
	buf[--i] = 0;
	neg = n < 0 ? 1 : 0;
	n = n < 0 ? n : -n;
	carac = (long long)n;
	if (precision)
		i = ft_ftoa_mantis(buf, carac, n, precision);
	if (carac == 0)
		buf[--i] = '0';
	while (carac)
	{
		buf[--i] = -(carac % 10) + '0';
		carac /= 10;
	}
	if (neg)
		buf[--i] = '-';
	ret = ft_strdup(&buf[i]);
	return (ret);
}
