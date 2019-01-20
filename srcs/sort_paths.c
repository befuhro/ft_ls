/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_paths.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:19:36 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_for_swap(char *file1, char *file2, int options)
{
	struct stat info_file1;
	struct stat info_file2;

	lstat(file1, &info_file1);
	lstat(file2, &info_file2);
	if (!(options & B_TIME))
	{
		if (S_ISDIR(info_file1.st_mode) && S_ISREG(info_file2.st_mode))
			return (1);
		else if (S_ISREG(info_file1.st_mode) && S_ISDIR(info_file2.st_mode))
			return (0);
		if (!(options & B_REV) && ft_strcmp(file1, file2) > 0)
			return (1);
		if (options & B_REV && ft_strcmp(file1, file2) < 0)
			return (1);
	}
	return (0);
}

int		check_swap_time(char *file1, char *file2, int options)
{
	struct stat info_file1;
	struct stat info_file2;

	lstat(file1, &info_file1);
	lstat(file2, &info_file2);
	if (S_ISDIR(info_file1.st_mode) && S_ISREG(info_file2.st_mode))
		return (1);
	else if (S_ISREG(info_file1.st_mode) && S_ISDIR(info_file2.st_mode))
		return (0);
	if (!(options & B_REV) && info_file1.st_mtime < info_file2.st_mtime)
		return (1);
	if (!(options & B_REV) && info_file1.st_mtime == info_file2.st_mtime &&
			ft_strcmp(file1, file2) > 0)
		return (1);
	if (options & B_REV && info_file1.st_mtime > info_file2.st_mtime)
		return (1);
	if ((options & B_REV) && info_file1.st_mtime == info_file2.st_mtime &&
			ft_strcmp(file1, file2) < 0)
		return (1);
	return (0);
}

char	**sort_paths(int size, char **args, int options)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = -1;
	if (!(paths = malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i++ < size - 1)
		paths[i] = args[i];
	i = -1;
	while (i++ < size - 2)
	{
		if ((!(options & B_TIME) &&
			check_for_swap(paths[i], paths[i + 1], options)) ||
			(options & B_TIME &&
			check_swap_time(paths[i], paths[i + 1], options)))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = -1;
		}
	}
	return (paths);
}
