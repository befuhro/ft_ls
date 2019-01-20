/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 03:42:47 by befuhro     ###    #+. /#+    ###.fr     */
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

int		main(int ac, char **av)
{
	int		options;
	int 	index_path;

	options = 0;
	index_path = index_for_path(ac, av, &options);
	handle_args(av + index_path + 1, options);
	return (0);
}
