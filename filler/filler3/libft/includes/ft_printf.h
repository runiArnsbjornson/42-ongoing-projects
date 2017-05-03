/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:44:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/20 13:08:03 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <locale.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../Libft/libft.h"

typedef struct		s_flag
{
	int				len;
	int				lag_h;
	int				lag_hh;
	int				lag_l;
	int				lag_ll;
	int				lag_long;
	int				lag_j;
	int				lag_z;
	int				lag_dot;
	int				lag_htag;
	int				lag_zero;
	int				lag_minus;
	int				lag_plus;
	int				lag_space;
	int				width;
	int				preci;
	int				sign;
	int				i;
	char			conv;
	char			start;
}					t_flag;
/*
** handlers
*/
int					bin_handler(va_list args, t_flag *f);
int					char_handler(va_list args, t_flag *f);
int					dec_handler(va_list args, t_flag *f);
int					float_handler(va_list args, t_flag *f);
int					hex_handler(va_list args, t_flag *f);
int					oct_handler(va_list args, t_flag *f);
int					percent_handler(t_flag *f);
int					string_handler(va_list args, t_flag *f);
char				*utf8_convert(char *buf, size_t buf_size, int code);
/*
** srcs/func.c
*/
long double			float_size(long double n, va_list args, t_flag *f);
void				get_preci(const char *fmt, t_flag *f, va_list args, int i);
void				get(const char *fmt, t_flag *f, va_list args, int i);
long long			int_size(long long n, va_list args, t_flag *f);
void				precision(const char *fmt, t_flag *f, va_list args, int i);
int					printer(const char *s, t_flag *f, int len);
void				search(const char *fmt, t_flag *f, va_list args, int i);
unsigned long long	uint_size(unsigned long long n, va_list args, t_flag *f);
void				wprinter(const wchar_t *ls, t_flag *f, int len);
int					zero_fill(char *buf, int i, t_flag *f, int len);

#endif
