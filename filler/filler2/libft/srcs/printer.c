/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:22:15 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 12:02:20 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		string_width(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	len = f->preci < len ? f->preci : len;
	while (f->width > len)
	{
		if (f->lag_zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		--f->width;
		++pc;
	}
	write(1, s, len);
	pc += len;
	return (pc);
}

int		string_printer(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->lag_minus)
	{
		len = f->preci < len ? f->preci : len;
		write(1, s, len);
		pc += len;
		while (f->width > pc)
		{
			write(1, " ", 1);
			++pc;
		}
	}
	else
		pc += string_width(s, f, len);
	return (pc);
}

int		print_width(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	while (f->width && f->width > len)
	{
		if (f->lag_zero && (f->conv == 's' || f->conv == 'S' || f->conv == 'c'
		|| f->conv == 'C'))
			write(1, "0", 1);
		else
			write(1, " ", 1);
		--f->width;
		++pc;
	}
	write(1, s, len);
	pc += len;
	return (pc);
}

int		printer(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->lag_dot && (f->conv == 's' || f->conv == 'S'))
		pc += string_printer(s, f, len);
	else
	{
		if (f->lag_minus)
		{
			write(1, s, len);
			pc += len;
			while (f->width > pc)
			{
				write(1, " ", 1);
				++pc;
			}
		}
		else
			pc += print_width(s, f, len);
	}
	return (pc);
}
