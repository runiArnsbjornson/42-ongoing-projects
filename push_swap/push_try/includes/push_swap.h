/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:46:47 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/23 16:24:17 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_check
{
	int	error;
	int	dbl;
	int unsort;
	int	size;
	int	*a;
}				t_check;

typedef struct	s_lst
{
	int				x;
	struct s_lst	*prec;
	struct s_lst	*next;
}				t_lst;

int				calc(t_check *c);

#endif
