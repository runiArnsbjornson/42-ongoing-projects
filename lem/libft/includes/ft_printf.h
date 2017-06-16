/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:44:10 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/16 13:42:56 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <locale.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <libft.h>

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
int					bin_format(char *buf, int i, t_flag *f, int len);
char				*bin_to_string(char *buf, int i,
	unsigned long long n, t_flag *f);
int					bin_handler(va_list args, t_flag *f);
/*
** char
*/
int					char_handler(va_list args, t_flag *f);
/*
** dec
*/
int					dec_handler(va_list args, t_flag *f);
char				*udec_to_string(char *buf, int i,
	unsigned long long n, t_flag *f);
char				*dec_to_string(char *buf, int i, long long n, t_flag *f);
int					dec_format(char *buf, int i, t_flag *f, int len);
int					sign_dec(char *buf, int i, t_flag *f, int len);
/*
** float
*/
int					sign_float(char *buf, int i, t_flag *f, int len);
int					float_format(char *buf, int i, t_flag *f, int len);
int					float_mantis(char *buf, int i, t_flag *f,
	long double mantis);
char				*float_to_string(char *buf, int i,
	long double n, t_flag *f);
int					float_handler(va_list args, t_flag *f);
/*
** hex
*/
int					hex_preci_zero(char *buf, int i, t_flag *f, int len);
char				*hex_to_string(char *buf, int i,
	unsigned long long n, t_flag *f);
int					hex_handler(va_list args, t_flag *f);
/*
** oct
*/
int					oct_preci_zero(char *buf, int i, t_flag *f, int len);
char				*oct_to_string(char *buf, int i,
	unsigned long long n, t_flag *f);
int					oct_handler(va_list args, t_flag *f);
/*
** %
*/
int					percent_handler(t_flag *f);
/*
** string
*/
int					wstring_handler(va_list args, t_flag *f);
int					string_handler(va_list args, t_flag *f);
/*
** uchar
*/
int					numberbits(unsigned int code);
void				push_char(char *buf, size_t *index, char eob);
void				push_uchar(char *buf, size_t *index, unsigned char eohex);
char				*utf8_convert(char *buf, size_t buf_size, int code);
/*
** srcs/search.c
*/
char				check_conv(const char c);
int					check_flag(const char c);
void				search(const char *fmt, t_flag *f, va_list args, int i);
/*
** srcs/main.c
*/
int					ft_parse(const char *fmt, t_flag *f, va_list args);
int					no_conv_handler(char fmt, t_flag *f);
void				zero_struct(t_flag *f);
int					ft_handlers(va_list args, t_flag *f, int pc);
/*
** srcs/func.c
*/
long double			float_size(long double n, va_list args, t_flag *f);
long long			int_size(long long n, va_list args, t_flag *f);
unsigned long long	uint_size(unsigned long long n, va_list args, t_flag *f);
int					htag_format(char *buf, int i, t_flag *f, int len);
int					zero_fill(char *buf, int i, t_flag *f, int len);
/*
** srcs/get.c
*/
void				get(const char *fmt, t_flag *f, va_list args, int i);
void				get_flag(const char *fmt, t_flag *f, va_list args);
void				check_size(const char *fmt, t_flag *f, int i);
/*
** srcs/precision.c
*/
int					width_digit(const char *fmt, t_flag *f, int i, int flag);
void				precision(const char *fmt, t_flag *f, va_list args, int i);
void				get_preci(const char *fmt, t_flag *f, va_list args, int i);
/*
** srcs/printer.c
*/
int					string_width(const char *s, t_flag *f, int len);
int					string_printer(const char *s, t_flag *f, int len);
int					print_width(const char *s, t_flag *f, int len);
int					printer(const char *s, t_flag *f, int len);
/*
** srcs/wprinter.c
*/
void				wstring_width(const wchar_t *ls,
	t_flag *f, int len, int byte_len);
void				wstring_printer(const wchar_t *ls, t_flag *f, int len);
void				wprint_minus(const wchar_t *ls, t_flag *f, int len);
void				wprint_width(const wchar_t *ls, t_flag *f, int len);
void				wprinter(const wchar_t *ls, t_flag *f, int len);

#endif
