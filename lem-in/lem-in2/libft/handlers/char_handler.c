/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:24:50 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/17 17:09:18 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_handler(va_list args, t_flag *f)
{
	char	scr[2];
	char	wscr[8];
	char	*uchar;
	wchar_t wchar;

	if (ft_isupper(f->conv) == 1)
		f->lag_l = 1;
	if (f->lag_l == 1)
	{
		wchar = va_arg(args, wchar_t);
		uchar = utf8_convert(wscr, 8, wchar);
		if (wchar == 0)
			return (printer("", f, 1));
		return (printer(uchar, f, ft_strlen(uchar)));
	}
	else
	{
		scr[0] = (char)va_arg(args, int);
		scr[1] = 0;
		return (printer(scr, f, 1));
	}
}
