/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 00:11:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/09 13:07:07 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char *ft_endless_strjoin(int nbr, ...);

char	*ft_short_path(char *path, char *mode)
{
	char *short_path;
	if (ft_bool_strchr(path, '/'))
	{
		if (mode[0] == '-')
			return (ft_strrchr(path, '/') + 1);
		if (mode[0] == 'd')
		{
			short_path = ft_endless_strjoin(3, BOL, (ft_strrchr(path, '/') + 1), RES);
			return (short_path);
		}
		if (mode[0] == 'l')
		{
			short_path = ft_endless_strjoin(3, MAG, ft_strrchr(path, '/') + 1, RES);
			return (short_path);
		}
	}
	return (path);
}

char	*ft_mode(int mode)
{
	char *ret;
	mode_t mod;

	ret = malloc(sizeof(char) * 11);
	S_ISLNK(mode) ? ret[0] = 'l' : 0;
	S_ISCHR(mode) ? ret[0] = 'c' : 0;
	S_ISDIR(mode) ? ret[0] = 'd' : 0;
	S_ISREG(mode) ? ret[0] = '-' : 0;
	S_ISFIFO(mode) ? ret[0] = 'p' : 0;
	S_ISBLK(mode) ? ret[0] = 'b' : 0;
	S_ISSOCK(mode) ? ret[0] = 's' : 0;
	mod = (mode & ~S_IFMT);
	ret[1] = (mod & S_IRUSR) ? 'r' : '-';
	ret[2] = (mod & S_IWUSR) ? 'w' : '-';
	ret[3] = (mod & S_IXUSR) ? 'x' : '-';
	ret[4] = (mod & S_IRGRP) ? 'r' : '-';
	ret[5] = (mod & S_IWGRP) ? 'w' : '-';
	ret[6] = (mod & S_IXGRP) ? 'x' : '-';
	ret[7] = (mod & S_IROTH) ? 'r' : '-';
	ret[8] = (mod & S_IWOTH) ? 'w' : '-';
	ret[9] = (mod & S_IXOTH) ? 'x' : '-';
	ret[10] = 0;
	return (ret);
}

int	main(int ac, char **av)
{
	int i;
	int fd;
	t_stats	*sta;
	char *ti;
	char *mode;
	char *path;

	i = 1;
	sta = malloc(sizeof(t_stats));
	sta->fs = malloc(sizeof(struct stat));
	sta->block = 0;
	while (i < ac)
	{
		if ((fd = fstatat(AT_FDCWD, av[i], sta->fs, AT_SYMLINK_NOFOLLOW)) == 0)
		{
			sta->block += sta->fs->st_blocks;
			sta->uid = getpwuid(sta->fs->st_uid);
			sta->gid = getgrgid(sta->fs->st_gid);
			ti = ctime(&sta->fs->st_atime);
			mode = ft_mode(sta->fs->st_mode);
			path = ft_short_path(av[i], mode);
			printf("%s %-u\t%-s\t%-s\t%-lld\t%-.12s\t%-s\n", mode, sta->fs->st_nlink, sta->uid->pw_name, sta->gid->gr_name, sta->fs->st_size, &ti[4], path);
		}
		else
		{
			printf("fd=%d\n", fd);
			perror("");
		}
		i++;
	}
	printf("block=%lu\n", sta->block);
	close(fd);
	return (0);
}
