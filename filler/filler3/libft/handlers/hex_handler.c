/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:57:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/12 12:59:47 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			hex_preci_zero(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	if (f->lag_dot)
	{
		while (f->preci > len++)
			buf[--i] = '0';
	}
	else if (f->lag_zero && !f->lag_dot && !f->lag_minus && f->conv != 'p')
	{
		while (f->width > len++)
			buf[--i] = '0';
	}
	else if (f->lag_zero && f->lag_htag && !f->lag_dot && !f->lag_minus)
	{
		while (f->width - 2 > len++)
			buf[--i] = '0';
	}
	else
		buf[--i] = '0';
	if (f->conv == 'p')
	{
		buf[--i] = f->start == 'a' ? 'x' : 'X';
		buf[--i] = '0';
	}
	return (i);
}

char		*hex_to_string(char *buf, int i, unsigned long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		i = hex_preci_zero(buf, i, f, 0);
		return (&buf[i]);
	}
	while (n)
	{
		buf[--i] = n % 16 >= 10 ? n % 16 + f->start - 10 : n % 16 + '0';
		n /= 16;
	}
	i = zero_fill(buf, i, f, 0);
	return (&buf[i]);
}

int			hex_handler(va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[32 + f->width + f->preci];

	if (f->conv == 'X')
		f->start = 'A';
	if (f->conv == 'p')
		f->lag_htag = 1;
	n = uint_size(0, args, f);
	s = hex_to_string(buf, 32 + f->width + f->preci, n, f);
	return (printer(s, f, ft_strlen(s)));
}
