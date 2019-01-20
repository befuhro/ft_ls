/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:16:35 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	create_options_byte(char *options, int *byte)
{
	if (!(*byte & B_TIME))
		*byte = (ft_strchr(options, 't')) ? *byte + B_TIME : *byte;
	if (!(*byte & B_REC))
		*byte = (ft_strchr(options, 'R')) ? *byte + B_REC : *byte;
	if (!(*byte & B_REV))
		*byte = (ft_strchr(options, 'r')) ? *byte + B_REV : *byte;
	if (!(*byte & B_ALL))
		*byte = (ft_strchr(options, 'a')) ? *byte + B_ALL : *byte;
	if (!(*byte & B_LIST))
		*byte = (ft_strchr(options, 'l')) ? *byte + B_LIST : *byte;
}

int		is_right(char *av)
{
	int i;

	i = 1;
	while (av[i] != '\0')
	{
		if (av[i] != 't' && av[i] != 'r' && av[i] != 'l' &&
				av[i] != 'R' && av[i] != 'a')
			return (-1);
		i++;
	}
	return (0);
}

int		index_for_path(int ac, char **av, int *options)
{
	int			i;
	struct stat	buf;

	i = 0;
	while (*av[i++] && ac > i)
	{
		if (av[i][0] == '-')
		{
			if (!(av[i][1]))
				return (-1);
			if (is_right(av[i]) == -1)
				return (-1);
			if (lstat(av[i], &buf) == -1)
				create_options_byte(av[i], options);
		}
		else
			return (i - 1);
	}
	return (i - 1);
}

int		main(int ac, char **av)
{
	int		options;
	int		index;
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
