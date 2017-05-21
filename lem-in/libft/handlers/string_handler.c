/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:52:03 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 15:17:45 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		wstring_handler(va_list args, t_flag *f)
{
	wchar_t	*ls;
	int		len;

	ls = va_arg(args, wchar_t *);
	if (ls != NULL)
	{
		if (f->lag_dot)
			len = (int)ft_wcsnbytelen(ls, (size_t)f->preci);
		else
			len = ft_wcsbytelen(ls);
		len = f->width > len ? f->width : len;
		if (ft_wcscmp(ls, L"") == 0)
			return (printer("", f, 0));
		else
			wprinter(ls, f, (int)ft_wcslen(ls));
		return (len);
	}
	f->width += f->lag_space == 1 ? 1 : 0;
	return (printer("(null)", f, 6));
}

int		string_handler(va_list args, t_flag *f)
{
	char	*s;

	if (ft_isupper(f->conv) == 1)
		f->lag_l = 1;
	if (f->lag_l)
		return (wstring_handler(args, f));
	else
	{
		s = (char *)va_arg(args, char *);
		if (s != NULL)
			return (printer(s, f, (int)ft_strlen(s)));
	}
	f->width += f->lag_space == 1 ? 1 : 0;
	return (printer("(null)", f, 6));
}
