/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_paths.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 02:49:35 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 23:20:12 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	handle_path(char *path, int options)
{
	DIR			*directorie;

	if ((directorie = opendir(path)) == NULL)
	{
		ft_putstr("ft_ls: ");
		perror(path);
	}
	else
		list_dir(options, directorie, path);
}

void	handle_paths(char **paths, int options)
{
	if (*paths != NULL)
	{
		while (*paths != NULL)
		{
			handle_path(*paths, options);
			paths++;
		}
	}
	else
		handle_path(".", options);
}

void	throw_error_path(char **paths, int length_array)
{
	struct stat	info;
	int			i;
	DIR			*directorie;

	i = 0;
	while (i < length_array)
	{
		if (stat(paths[i], &info) == -1)
		{
			ft_putstr("ft_ls: ");
			perror(paths[i]);
		}
		if ((directorie = opendir(paths[i])) == NULL)
		{
			if (errno != ENOTDIR && errno != ENOENT)
				perror(paths[i]);
		}
		else
			closedir(directorie);
		i++;
	}
}

void	handle_args(char **paths, int options, int length_array)
{
	int			i;
	DIR			*directorie;
	struct stat info;

	i = 0;
	if (*paths != NULL)
	{
		throw_error_path(paths, length_array);
		while (i < length_array)
		{
			if (stat(paths[i], &info) != -1 && (S_ISREG(info.st_mode) == 1))
				handle_file(paths[i], options);
			else if ((directorie = opendir(paths[i])) != NULL)
				list_dir(options, directorie, paths[i]);
			i++;
		}
		free(paths);
	}
	else
		handle_path(".", options);
}
