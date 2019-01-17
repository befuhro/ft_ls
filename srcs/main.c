/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:11 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 00:47:32 by befuhro     ###    #+. /#+    ###.fr     */
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

void	get_total(s_file *file, int *total)
{
	if (file != NULL)
	{
		get_total(file->left, total);
		*total += file->blocks;
		get_total(file->right, total);
	}
}

void	list_dir(int options, DIR *directorie, char *path)
{
	s_file	*files;
	s_path *list;
	int total;

	total = 0;
	list = NULL;
	files = run_through_dir(options, directorie, path, &list);
	ft_putchar('\n');
	if (options & B_REC)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (options & B_LIST)
	{
		get_total(files, &total);
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
	print(files, options);
	dealloc_tree(files);
	closedir(directorie);
	handle_recursive(list, options);
}


void	handle_command(char *path, int options)
{
	DIR *directorie;

	if ((directorie = opendir(path)) == NULL)
		perror(path);
	else
		list_dir(options, directorie, path);
}

int		main(int ac, char **av)
{
	int options;
	if (av[1] != NULL)
		options = create_options_byte(av[1]);
	else
		options = 0;
	if (ac >= 2)
		handle_command(av[2], options);
	return (0);
}
