/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_paths.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 02:49:35 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 12:24:10 by ldaveau     ###    #+. /#+    ###.fr     */
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

void	handle_args(char **paths, int options)
{
	int			i;
	DIR			*directorie;
	struct stat info;

	i = 0;
	if (*paths != NULL)
	{
		while (paths[i] != NULL)
		{
			if (stat(paths[i], &info) == -1)
			{
				ft_putstr("ft_ls: ");
				perror(paths[i]);
			}
			i++;
		}
		i = 0;
		while (paths[i] != NULL)
		{
			if ((directorie = opendir(paths[i])) != NULL)
				list_dir(options, directorie, paths[i]);
			else if (stat(paths[i], &info) != -1)
				handle_file(paths[i], options);
			i++;
		}
		free(paths);
	}
	else
		handle_path(".", options);
}
