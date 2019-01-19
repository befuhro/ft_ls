/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 21:51:41 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int	 create_options_byte(char *options)
{
	int byte;

	byte = 0;
	byte = (ft_strchr(options, 't')) ? byte + B_TIME : byte;
	byte = (ft_strchr(options, 'R')) ? byte + B_REC : byte;
	byte = (ft_strchr(options, 'r')) ? byte + B_REV : byte;
	byte = (ft_strchr(options, 'a')) ? byte + B_ALL : byte;
	byte = (ft_strchr(options, 'l')) ? byte + B_LIST : byte;
	return (byte);
}

void	handle_path(char *path, int options)
{
	DIR *directorie;

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

int		main(int ac, char **av)
{
	int		options;
	char	**paths;

	paths = av + 2;
	if (av[1] != NULL)
		options = create_options_byte(av[1]);
	else
		options = 0;
	handle_paths(av + 2, options);
	(void)ac;
	return (0);
}
