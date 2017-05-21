/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:04:59 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/19 14:26:24 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	check_conv(const char c)
{
	const char	conv[19] = "%bcdfiopsuxBCDFOSUX";
	int			i;

	i = -1;
	while (i++ <= 18)
	{
		if (c == conv[i])
			return (conv[i]);
	}
	return (0);
}

int		check_flag(const char c)
{
	const char	flag[21] = "#.-+* hlLjz0123456789";
	int			i;

	i = -1;
	while (i++ <= 20)
	{
		if (c == flag[i])
			return (1);
	}
	return (0);
}

void	search(const char *fmt, t_flag *f, va_list args, int i)
{
	while (fmt[i] && fmt && check_flag(fmt[i]) != 0)
	{
		f->len++;
		i++;
	}
	while (fmt[f->i])
		++f->i;
	f->conv = check_conv(fmt[i]);
	get(fmt, f, args, 1);
}
