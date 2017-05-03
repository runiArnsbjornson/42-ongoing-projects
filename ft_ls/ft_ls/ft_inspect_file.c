/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 00:11:46 by jdebladi          #+#    #+#             */
/*   Updated: 2017/04/13 15:49:35 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_nstrjoin(int nbr, ...);

char	*ft_s_path(char *path, char *mod)
{
	char	*s_path;

	if (ft_bool_strchr(path, '/'))
	{
		s_path = ft_strrchr(path, '/') + 1;
		if (mod[0] == '-')
		{
			if (ft_bool_strchr(mod, 'x'))
				s_path = ft_nstrjoin(3, RED, s_path, RES);
		}
		else
		{
			mod[0] == 'p' ? s_path = ft_nstrjoin(3, YEL, s_path, RES) : 0;
			mod[0] == 'c' ? s_path = ft_nstrjoin(4, BLU, BYEL, s_path, RES) : 0;
			mod[0] == 'd' ? s_path = ft_nstrjoin(3, BOLD, s_path, RES) : 0;
			mod[0] == 'b' ? s_path = ft_nstrjoin(4, BLU, BCYA, s_path, RES) : 0;
			mod[0] == 'l' ? s_path = ft_nstrjoin(3, MAG, s_path, RES) : 0;
			mod[0] == 's' ? s_path = ft_nstrjoin(3, RED, s_path, RES) : 0;
		}
		return (s_path);
	}
	return (path);
}

char	*ft_mode(int mode)
{
	char	*ret;
	mode_t	mod;

	ret = malloc(sizeof(char) * 11);
	S_ISFIFO(mode) ? ret[0] = 'p' : 0;
	S_ISCHR(mode) ? ret[0] = 'c' : 0;
	S_ISDIR(mode) ? ret[0] = 'd' : 0;
	S_ISBLK(mode) ? ret[0] = 'b' : 0;
	S_ISREG(mode) ? ret[0] = '-' : 0;
	S_ISLNK(mode) ? ret[0] = 'l' : 0;
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

int		long_display(char *av, t_opt *o)
{
	int		fd;
	t_stats	*sta;

	sta = malloc(sizeof(t_stats));
	sta->fs = malloc(sizeof(struct stat));
	if ((fd = fstatat(AT_FDCWD, av, sta->fs, AT_SYMLINK_NOFOLLOW)) == 0)
	{
		sta->block += sta->fs->st_blocks;
		sta->uid = getpwuid(sta->fs->st_uid);
		sta->gid = getgrgid(sta->fs->st_gid);
		sta->ti = ctime(&sta->fs->st_atime);
		sta->mode = ft_mode(sta->fs->st_mode);
		sta->path = ft_s_path(av, sta->mode);
		printf("%s %4u %-10s %-10s %5lld %-.*s\t%-s\n", sta->mode, sta->fs->st_nlink, sta->uid->pw_name, sta->gid->gr_name, sta->fs->st_size, o->precise_time, &sta->ti[4], sta->path);
	}
	else
	{
		printf("fd=%d\n", fd);
		perror("");
	}
	close(fd);
	return (0);
}

// int		main(int ac, char **av)
// {
// 	int		i;
// 	int		fd;
// 	t_stats	*sta;
// 	char	*ti;
// 	char	*mode;
// 	char	*path;
//
// 	i = 1;
// 	sta = malloc(sizeof(t_stats));
// 	sta->fs = malloc(sizeof(struct stat));
// 	sta->block = 0;
// 	while (i < ac)
// 	{
// 		if ((fd = fstatat(AT_FDCWD, av[i], sta->fs, AT_SYMLINK_NOFOLLOW)) == 0)
// 		{
// 			sta->block += sta->fs->st_blocks;
// 			sta->uid = getpwuid(sta->fs->st_uid);
// 			sta->gid = getgrgid(sta->fs->st_gid);
// 			ti = ctime(&sta->fs->st_atime);
// 			mode = ft_mode(sta->fs->st_mode);
// 			path = ft_s_path(av[i], mode);
// 			printf("%s %-u\t%-s\t%-s\t%-lld\t%-.12s\t%-s\n", mode, sta->fs->st_nlink, sta->uid->pw_name, sta->gid->gr_name, sta->fs->st_size, &ti[4], path);
// 		}
// 		else
// 		{
// 			printf("fd=%d\n", fd);
// 			perror("");
// 		}
// 		i++;
// 	}
// 	printf("block=%lu\n", sta->block);
// 	close(fd);
// 	return (0);
// }
