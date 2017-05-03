/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:32:18 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/04 15:24:45 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <float.h>
# include <stdarg.h>

# define BUFF_SIZE 32
# define CLN "\x1B[K"
# define BOL "\x1B[01m"
# define FAI "\x1B[02m"
# define ITA "\x1B[03m"
# define UDL "\x1B[04m"
# define BLK "\x1B[30m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define BBLK "\x1B[40m"
# define BRED "\x1B[41m"
# define BGRN "\x1B[42m"
# define BYEL "\x1B[43m"
# define BBLU "\x1B[44m"
# define BMAG "\x1B[45m"
# define BCYN "\x1B[46m"
# define BWHT "\x1B[47m"
# define OVR "\x1B[53m"
# define RES "\x1B[00m"
# define ERROR ft_putendl_fd(RED "Error" RES, 2)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

long			ft_abs(int nb);
int				ft_atoi(const char *str);
int				ft_bool_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
char			*ft_ftoa(long double n, int precision);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isinf(double x);
int				ft_islower(int c);
int				ft_isnan(double x);
int				ft_isprime(int nb);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
char			*ft_itoa_base(long long n, int base);
char			*ft_itoa(int n);
long long		ft_lpwr(long long nb, int pwr);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_occurence(int n, char **argv);
int				ft_printf(const char *format, ...);
void			ft_putchar_fd(int c, int fd);
void			ft_putchar(int c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *str);
void			ft_puttab_fd(char **tab, int fd);
void			ft_puttab(char **tab);
int				ft_pwr(int nb, int power);
char			*ft_replace(const char *s, const char *old, const char *new);
char			**ft_split(char *str);
int				ft_sqrt(int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
int				ft_strequ(char const *s1, char const *s2);
int				ft_stris(const char *s, int (*f)(char));
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrealloc(char *s, size_t size);
char			*ft_strrev(char *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_tab(size_t col, size_t line);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_wcbytesize(wchar_t wc);
int				ft_wcsbytelen(wchar_t *wc);
int				ft_wcscmp(const wchar_t *s1, const wchar_t *s2);
size_t			ft_wcslen(const wchar_t *s);
int				ft_wcsnbytelen(const wchar_t *s, size_t n);
int				ft_wcsnlen(const wchar_t *s, size_t n);

/*
**	not ft_functions
*/

int				get_next_line(const int fd, char **line);

#endif
