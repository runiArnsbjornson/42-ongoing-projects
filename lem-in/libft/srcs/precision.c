/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:45:29 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:26:37 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		width_digit(const char *fmt, t_flag *f, int i, int flag)
{
	if (ft_isdigit(fmt[i]) == 1 && fmt[i - 1] != '.')
	{
		if (flag)
			f->lag_zero = 0;
		flag = 0;
		f->width = 0;
		while (ft_isdigit(fmt[i]) == 1)
		{
			if (fmt[i] == '0' && f->width == 0 && fmt[i - 1] != '-')
				f->lag_zero = 1;
			f->width *= 10;
			f->width += fmt[i] - '0';
			i++;
		}
	}
	return (i);
}

void	precision(const char *fmt, t_flag *f, va_list args, int i)
{
	int flag;

	flag = 0;
	while (fmt[i] && fmt != 0 && i <= f->len)
	{
		i = width_digit(fmt, f, i, flag);
		if (fmt[i] == '*' && fmt[i - 1] != '.')
		{
			flag = 1;
			f->width = va_arg(args, int);
			f->lag_minus = f->width < 0 ? 1 : f->lag_minus;
			f->lag_zero = f->width == 0 ? 1 : f->lag_zero;
			f->width = f->width < 0 ? -f->width : f->width;
		}
		if (fmt[i] == '.')
			break ;
		i++;
	}
}

void	get_preci(const char *fmt, t_flag *f, va_list args, int i)
{
	if (fmt[i] == '*')
	{
		f->preci = va_arg(args, int);
		f->lag_dot = f->preci < 0 ? 0 : 1;
		f->preci = f->preci < 0 ? 0 : f->preci;
	}
	else
	{
		f->preci = 0;
		while (ft_isdigit(fmt[i]) == 1)
		{
			f->preci *= 10;
			f->preci += fmt[i] - '0';
			i++;
		}
	}
}
