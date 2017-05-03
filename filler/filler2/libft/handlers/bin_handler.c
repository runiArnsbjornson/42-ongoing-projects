/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:58:02 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 12:55:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			bin_format(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	i = zero_fill(buf, i, f, len);
	if (f->lag_htag && buf[i] != '0')
		buf[--i] = '0';
	return (i);
}

char		*bin_to_string(char *buf, int i, unsigned long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		if (f->lag_dot == 1 && f->preci == 0)
		{
			if (f->lag_htag == 1)
				buf[--i] = '0';
			return (&buf[i]);
		}
		buf[--i] = '0';
	}
	while (n)
	{
		buf[--i] = n % 2 + '0';
		n /= 2;
	}
	i = bin_format(buf, i, f, 0);
	return (&buf[i]);
}

int			bin_handler(va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[64 + f->width + f->preci];

	if (ft_isupper(f->conv) == 1)
	{
		f->lag_ll = f->lag_l == 1 ? 1 : 0;
		f->lag_l = 1;
	}
	n = uint_size(0, args, f);
	s = bin_to_string(buf, 64 + f->width + f->preci, n, f);
	return (printer(s, f, ft_strlen(s)));
}
