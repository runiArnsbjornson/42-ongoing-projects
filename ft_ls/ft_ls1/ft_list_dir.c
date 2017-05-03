/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:41:23 by jdebladi          #+#    #+#             */
/*   Updated: 2017/03/26 18:14:40 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	DIR *dr;
	struct dirent *dp;

	if (ac == 2)
	{
		if (!(dr = opendir(av[1])))
			{
				printf("Error\n");
				return (0);
			}
		while ((dp = readdir(dr)) != NULL)
		{
			printf("%s\n", dp->d_name);
		}
		closedir(dr);
	}
	return (0);
}
