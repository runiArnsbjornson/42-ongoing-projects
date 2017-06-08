/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:32:18 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/02 15:17:15 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putlist(t_list **alst)
{
	t_list *tmp;

	tmp = *alst;
	while (tmp)
	{
		printf(">> %s\n", tmp->content);
		tmp = tmp->next;
	}
}
