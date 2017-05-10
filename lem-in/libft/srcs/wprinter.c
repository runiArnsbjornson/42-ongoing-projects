/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wprinter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 00:59:13 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 12:16:32 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	wstring_width(const wchar_t *ls, t_flag *f, int len, int byte_len)
{
	char	buf[8];
	char	*uchar;

	byte_len = ft_wcsnbytelen(ls, f->preci);
	while (f->width > byte_len)
	{
		if (f->lag_zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		--f->width;
	}
	while (len)
	{
		uchar = utf8_convert(buf, 8, *ls);
		write(1, uchar, ft_strlen(uchar));
		ls++;
		len--;
	}
}

void	wstring_printer(const wchar_t *ls, t_flag *f, int len)
{
	int		byte_len;
	char	buf[8];
	char	*uchar;

	byte_len = 0;
	len = ft_wcsnlen(ls, f->preci);
	if (f->lag_minus)
	{
		while (len)
		{
			uchar = utf8_convert(buf, 8, *ls);
			write(1, uchar, ft_strlen(uchar));
			byte_len += ft_wcbytesize(*ls);
			ls++;
			len--;
		}
		while (f->width > byte_len)
		{
			write(1, " ", 1);
			++byte_len;
		}
	}
	else
		wstring_width(ls, f, len, byte_len);
}

void	wprint_minus(const wchar_t *ls, t_flag *f, int len)
{
	int		byte_len;
	char	buf[8];
	char	*uchar;

	byte_len = ft_wcsbytelen((wchar_t *)ls);
	while (len)
	{
		uchar = utf8_convert(buf, 8, *ls);
		write(1, uchar, ft_strlen(uchar));
		++ls;
		--len;
	}
	while (f->width > byte_len)
	{
		write(1, " ", 1);
		++byte_len;
	}
}

void	wprint_width(const wchar_t *ls, t_flag *f, int len)
{
	len = ft_wcsbytelen((wchar_t *)ls);
	while (f->width > len)
	{
		if (f->lag_zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		f->width--;
	}
}

void	wprinter(const wchar_t *ls, t_flag *f, int len)
{
	char	buf[8];
	char	*uchar;

	if (f->lag_dot)
		wstring_printer(ls, f, len);
	else if (f->lag_minus)
		wprint_minus(ls, f, len);
	else
	{
		wprint_width(ls, f, len);
		while (len)
		{
			uchar = utf8_convert(buf, 8, *ls);
			write(1, uchar, ft_strlen(uchar));
			ls++;
			len--;
		}
	}
}
