/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:55:31 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/23 15:09:19 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	zero_struct(t_check *c)
{
	int i;

	i = 0;
	c->error = 0;
	c->dbl = 0;
	c->unsort = 0;
	c->size = 0;
	c->a = malloc(sizeof(int) * 64);
	while (i < 64)
		c->a[i++] = 0;
}

int	print_result(t_check *c)
{
	if (c->dbl || c->error)
		ft_putstr_fd(RED"Error\n"RES, 2);
	else if (c->unsort)
		ft_putstr(BLU"KO\n"RES);
	else
		ft_putstr(GRN BOL"OK\n"RES);
	return(0);
}

int	parse_param(char *param, t_check *c)
{
	static int	i = 0;
	int			j;
	int			flag;

	j = 0;
	while (param[j])
	{
		flag = 0;
		while (ft_isspace(param[j]))
		{
			++j;
			flag = 1;
		}
		if (param[j] == 0)
			break ;
		if (flag || j == 0)
		{
			flag = 0;
			c->a[i] = ft_atoi(&param[j]);
			i = ++c->size;
		}
		if (ft_isdigit(param[j]) == 0 && ft_isspace(param[j]) == 0)
			c->error = 1;
		++j;
	}
	return (0);
}

int check_dbl(t_check *c)
{
	int i;
	int j;

	i = 0;
	while (i < c->size)
	{
		j = 0;
		while (j < c->size)
		{
			if (j == i)
				++j;
			if (j < c->size && c->a[j] == c->a[i])
				c->dbl = 1;
			if (j < i && i < c->size && c->a[j] > c->a[i])
				c->unsort = 1;
			++j;
		}
		++i;
	}
	return (0);
}

int main(int ac, char **av)
{
	int		i;
	t_check	c;

	i = 1;
	zero_struct(&c);
	while (i < ac)
	{
		parse_param(av[i], &c);
		i++;
	}
	i = 0;
	check_dbl(&c);
	while (i < c.size)
	{
		printf("a[%d]=%d\n", i, c.a[i]);
		i++;
	}
	calc(&c);
	return (0);
}
