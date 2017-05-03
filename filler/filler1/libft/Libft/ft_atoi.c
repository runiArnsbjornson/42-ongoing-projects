/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:09:26 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/09 13:09:59 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int ret;

	i = 0;
	n = 1;
	ret = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (ret * n);
		ret = (ret * 10 + (str[i]) - '0');
		i++;
	}
	return (ret * n);
}
