/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:26:51 by jdebladi          #+#    #+#             */
/*   Updated: 2017/05/21 09:36:17 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_error(char *str)
{
	ft_putstr_fd(RED "ERROR" RES, 2);
	if (str)
	{
		ft_putstr_fd(" : ", 2);
		ft_putendl_fd(str, 2);
	}
}
