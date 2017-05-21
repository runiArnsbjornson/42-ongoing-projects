/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:32:21 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:26:30 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	check_size(const char *fmt, t_flag *f, int i)
{
	if (fmt[i + 1] != 0)
	{
		if (fmt[i] == 'h' && fmt[i + 1] == 'h')
			f->lag_hh = 1;
		else if (fmt[i] == 'h')
			f->lag_h = 1;
		else if (fmt[i] == 'l' && fmt[i + 1] == 'l')
			f->lag_ll = 1;
		else if (fmt[i] == 'l')
			f->lag_l = 1;
	}
}

void	get_flag(const char *fmt, t_flag *f, va_list args)
{
	if (*fmt == '+')
		f->lag_plus = 1;
	if (*fmt == ' ')
		f->lag_space = 1;
	if (*fmt == '-')
		f->lag_minus = 1;
	if (*fmt == '#')
		f->lag_htag = 1;
	if (*fmt == '.')
	{
		f->lag_dot = 1;
		get_preci(fmt, f, args, 1);
	}
	if (*fmt == 'j')
		f->lag_j = 1;
	if (*fmt == 'z')
		f->lag_z = 1;
	if (*fmt == 'L')
		f->lag_long = 1;
	if (*fmt == 'h' || *fmt == 'l')
		check_size(fmt, f, 0);
}

void	get(const char *fmt, t_flag *f, va_list args, int i)
{
	precision(fmt, f, args, 1);
	while (fmt[i] && fmt && i <= f->len)
	{
		get_flag(&fmt[i], f, args);
		i++;
	}
}
