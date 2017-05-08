/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:33:05 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 13:08:28 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_struct(t_flag *f)
{
	f->len = 0;
	f->lag_h = 0;
	f->lag_hh = 0;
	f->lag_l = 0;
	f->lag_ll = 0;
	f->lag_long = 0;
	f->lag_j = 0;
	f->lag_z = 0;
	f->lag_dot = 0;
	f->lag_htag = 0;
	f->lag_zero = 0;
	f->lag_minus = 0;
	f->lag_plus = 0;
	f->lag_space = 0;
	f->width = 0;
	f->preci = 0;
	f->sign = 0;
	f->i = 1;
	f->conv = 0;
	f->start = 'a';
}

int		ft_handlers(va_list args, t_flag *f, int pc)
{
	pc = 0;
	if (f->conv == 'o' || f->conv == 'O')
		pc += oct_handler(args, f);
	else if (f->conv == 'd' || f->conv == 'i' || f->conv == 'D')
	{
		f->sign = 1;
		pc += dec_handler(args, f);
	}
	else if (f->conv == 'b' || f->conv == 'B')
		pc += bin_handler(args, f);
	else if (f->conv == 'u' || f->conv == 'U')
		pc += dec_handler(args, f);
	else if (f->conv == 'x' || f->conv == 'X' || f->conv == 'p')
		pc += hex_handler(args, f);
	else if (f->conv == 'c' || f->conv == 'C')
		pc += char_handler(args, f);
	else if (f->conv == 's' || f->conv == 'S')
		pc += string_handler(args, f);
	else if (f->conv == 'f' || f->conv == 'F')
		pc += float_handler(args, f);
	else if (f->conv == '%')
		pc += percent_handler(f);
	return (pc);
}

int		no_conv_handler(char fmt, t_flag *f)
{
	int		pc;
	int		j;
	char	buf[2 + f->width];

	pc = 0;
	j = 2 + f->width;
	buf[--j] = 0;
	if (f->conv == 0)
	{
		buf[--j] = fmt;
		j = zero_fill(buf, j, f, 0);
		pc += printer(&buf[j], f, ft_strlen(&buf[j]));
		zero_struct(f);
	}
	else
	{
		write(1, &fmt, 1);
		++pc;
	}
	return (pc);
}

int		ft_parse(const char *fmt, t_flag *f, va_list args)
{
	int pc;
	int i;

	pc = 0;
	i = 0;
	while (fmt[i] && fmt)
	{
		if (fmt[i] == '%')
		{
			zero_struct(f);
			search(&fmt[i], f, args, 1);
			if (f->conv == 0 && f->i == 1)
				return (pc);
			f->len = f->conv == 0 ? f->len - 1 : f->len;
			pc += ft_handlers(args, f, pc);
			i += f->len + 1;
		}
		else
			pc += no_conv_handler(fmt[i], f);
		i++;
	}
	return (pc);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	f;
	int		char_written;

	char_written = 0;
	zero_struct(&f);
	va_start(args, format);
	char_written += ft_parse(format, &f, args);
	va_end(args);
	return (char_written);
}
