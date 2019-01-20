/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 07:10:15 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

void    create_options_byte(char *options, int *byte)
{
	if (!(*byte & B_TIME))
		*byte = (ft_strchr(options, 't')) ? *byte + B_TIME : *byte;
	if (!(*byte & B_REC))
		*byte = (ft_strchr(options, 'R')) ? *byte + B_REC : *byte;
	if (!(*byte & B_REV))
		*byte = (ft_strchr(options, 'r')) ? *byte + B_REV : *byte;
	if (!(*byte & B_ALL))
		*byte = (ft_strchr(options, 'a')) ? *byte + B_ALL : *byte;
	if (!(*byte & B_TIME))
		*byte = (ft_strchr(options, 'l')) ? *byte + B_LIST : *byte;
}

int		index_for_path(int ac, char **av, int *options)
{
	int i;
	struct stat buf;

	i = 0;
	while (*av[i++] && ac > i)
	{
		if (av[i][0] == '-')
		{
			if (lstat(av[i], &buf) == -1)
				create_options_byte(av[i], options);
		}
		else
			return (i - 1);
	}
	return (i - 1);
}

char	**sort_paths(int size, char **args, int options)
{
	int		i;
	char	*tmp;
	char	**paths;

	i = -1;
	paths = malloc(sizeof(char*) * size + 1);
	while (i++ < size - 1)
		paths[i] = args[i];
	i = -1;
	while (i++ < size - 2)
	{
		if ((ft_strcmp(paths[i], paths[i + 1]) > 0  && !(options & B_REV)) ||
			(ft_strcmp(paths[i], paths[i + 1]) < 0  && options & B_REV))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = - 1;
		}
	}
	paths[i + 1] = NULL;
	return (paths);
}

int		main(int ac, char **av)
{
	int		options;
	int 	index;
	char	**paths;

	paths = NULL;
	options = 0;
	index = index_for_path(ac, av, &options);
	if (ac - index > 2)
		options = options + B_MULTI;
	if (ac == index + 1)
		handle_args(av + index + 1, options);
	else
	{
		paths = sort_paths(ac - index - 1, av + index + 1, options);
		handle_args(paths, options);
	}
	return (0);
}
