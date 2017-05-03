/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:51:23 by jdebladi          #+#    #+#             */
/*   Updated: 2016/12/08 17:45:55 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF_SIZE 10

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_bsq
{
	int		nb_line;
	char	obs;
	char	emp;
	char	sqr;
	int		max;
	int		coordi;
	int		coordj;
	char	**tab;
	int		**res;
}				t_bsq;

char			**ft_split(char *str);
char			*ft_strcut(const char *str, int begin, int len);
char			*ft_strdup(char *src);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_str_nb_line(char *str);
int				check_map(char *str, t_bsq *data);
void			ft_putchar(char c);
void			ft_display(t_bsq *data);
t_bsq			*ft_resolve(t_bsq *data);

#endif
