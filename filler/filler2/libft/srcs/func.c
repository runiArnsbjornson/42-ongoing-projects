/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:22:14 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 13:19:30 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double			float_size(long double n, va_list args, t_flag *f)
{
	if (f->lag_long)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	return (n);
}

long long			int_size(long long n, va_list args, t_flag *f)
{
	if (f->lag_ll == 1)
		n = va_arg(args, long long);
	else if (f->lag_j == 1)
		n = (intmax_t)va_arg(args, long long);
	else if (f->lag_z == 1)
		n = va_arg(args, ssize_t);
	else if (f->lag_l == 1)
		n = va_arg(args, long);
	else if (f->lag_hh == 1)
		n = (signed char)va_arg(args, int);
	else if (f->lag_h == 1)
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);
	return (n);
}

unsigned long long	uint_size(unsigned long long n, va_list args, t_flag *f)
{
	if (f->conv == 'p')
		n = (long)va_arg(args, void *);
	else if (f->lag_ll == 1)
		n = va_arg(args, unsigned long long);
	else if (f->lag_l == 1)
		n = va_arg(args, unsigned long);
	else if (f->lag_hh == 1)
		n = (unsigned char)va_arg(args, unsigned int);
	else if (f->lag_h == 1)
		n = (unsigned short)va_arg(args, unsigned int);
	else if (f->lag_j == 1)
		n = (uintmax_t)va_arg(args, unsigned long long);
	else if (f->lag_z == 1)
		n = va_arg(args, size_t);
	else
		n = va_arg(args, unsigned int);
	return (n);
}

int					htag_format(char *buf, int i, t_flag *f, int len)
{
	len = 0;
	if (f->conv == 'o' || f->conv == 'O' || f->conv == 'x' || f->conv == 'X' ||
	f->conv == 'p')
	{
		if (f->lag_htag && f->conv != 'o' && f->conv != 'O')
		{
			if (f->conv == 'x' || f->conv == 'X' || f->conv == 'p')
				buf[--i] = f->start == 'a' ? 'x' : 'X';
			buf[--i] = '0';
		}
		if (f->lag_htag && (f->conv == 'o' || f->conv == 'O'))
		{
			if (f->lag_dot && f->preci)
			{
				i = buf[i] == '0' ? i : i - 1;
				buf[i] = '0';
			}
			else
				buf[--i] = '0';
		}
	}
	return (i + len);
}

int					zero_fill(char *buf, int i, t_flag *f, int len)
{
	int size;

	len = ft_strlen(&buf[i]);
	if (f->lag_dot && f->conv != '%' && f->conv)
	{
		while (f->preci > len++)
			buf[--i] = '0';
	}
	if ((f->lag_zero && !f->lag_dot && !f->lag_htag && !f->lag_minus) ||
		((f->conv == '%' || f->conv == 0) && f->lag_zero))
	{
		while (f->width > len++)
			buf[--i] = '0';
	}
	if (f->lag_zero && !f->lag_dot && f->lag_htag && !f->lag_minus)
	{
		if (f->conv == 'o' || f->conv == 'O')
			size = 1;
		if (f->conv == 'x' || f->conv == 'X' || f->conv == 'p')
			size = 2;
		while (f->width - size > len++)
			buf[--i] = '0';
	}
	i = htag_format(buf, i, f, 0);
	return (i);
}
