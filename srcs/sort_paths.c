/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_paths.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 17:10:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:07:52 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_for_swap(char *file1, char *file2, int options)
{
	struct stat info_file1;
	struct stat info_file2;

	if (!(options & B_TIME))
	{
		if (!(options & B_REV) && ft_strcmp(file1, file2) > 0)
			return (1);
		if (options & B_REV && ft_strcmp(file1, file2) < 0)
			return (1);
	}
	else
	{
		lstat(file1, &info_file1);
		lstat(file2, &info_file2);
		if (!(options & B_REV) && info_file1.st_mtime < info_file2.st_mtime)
			return (1);
		if (!(options & B_REV) && info_file1.st_mtime == info_file2.st_mtime &&
				ft_strcmp(file1, file2) > 0)
			return (1);
		if (options & B_REV &&  info_file1.st_mtime > info_file2.st_mtime)
			return (1);
		if ((options & B_REV) && info_file1.st_mtime == info_file2.st_mtime &&
				ft_strcmp(file1, file2) < 0)
			return (1);
	}
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
		if (check_for_swap(paths[i], paths[i + 1], options))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = -1;
		}
	}
	paths[i + 1] = NULL;
	return (paths);
}
