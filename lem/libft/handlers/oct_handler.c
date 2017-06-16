/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:20:01 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 15:21:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			oct_preci_zero(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	if (f->lag_dot && f->preci == 0 && !f->lag_htag)
		return (i);
	else if (f->lag_dot && f->preci)
	{
		while (f->preci > len++)
			buf[--i] = '0';
	}
	else if (f->lag_zero && !f->lag_dot)
	{
		while (f->width > len++)
			buf[--i] = '0';
	}
	else
		buf[--i] = '0';
	return (i);
}

char		*oct_to_string(char *buf, int i, unsigned long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		i = oct_preci_zero(buf, i, f, 0);
		return (&buf[i]);
	}
	while (n)
	{
		buf[--i] = n % 8 + '0';
		n /= 8;
	}
	i = zero_fill(buf, i, f, 0);
	return (&buf[i]);
}

int			oct_handler(va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[32 + f->width + f->preci];

	if (ft_isupper(f->conv) == 1)
	{
		f->lag_ll = f->lag_l == 1 ? 1 : 0;
		f->lag_l = 1;
	}
	n = uint_size(0, args, f);
	s = oct_to_string(buf, 32 + f->width + f->preci, n, f);
	return (printer(s, f, (int)ft_strlen(s)));
}
