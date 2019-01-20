/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_dir.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:14 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:23:00 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_total(t_file *file, int *total)
{
	if (file != NULL)
	{
		get_total(file->left, total);
		*total += file->blocks;
		get_total(file->right, total);
	}
}

t_file	*run_through_dir(int options, DIR *directorie, char *path,
		t_path **list)
{
	t_file	*files;
	t_file	file;
	char	*entire_path;

	files = NULL;
	entire_path = NULL;
	while ((file.info = readdir(directorie)))
	{
		entire_path = append_path(path, file.info->d_name);
		if (!(file.stat = malloc(sizeof(struct stat))))
			return (NULL);
		lstat(entire_path, file.stat);
		if (file.info->d_name[0] != '.' || (options & B_ALL))
		{
			place_file(options, file, &files, entire_path);
			if (S_ISDIR(file.stat->st_mode) && options & B_REC &&
					ft_strcmp(file.info->d_name, ".") &&
					ft_strcmp(file.info->d_name, ".."))
				append_recursive_tree(entire_path, list, options);
		}
		ft_strdel(&entire_path);
		entire_path = NULL;
		free(file.stat);
	}
	return (files);
}

void	display_total(t_file file)
{
	int total;

	get_total(&file, &total);
	if (total)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

void	list_dir(int options, DIR *directorie, char *path)
{
	t_file	*files;
	t_path	*list;

	list = NULL;
	files = run_through_dir(options, directorie, path, &list);
	ft_putchar('\n');
	if (options & B_REC || options & B_MULTI)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (options & B_LIST)
		display_total(*files);
	print(files, options);
	dealloc_tree(files);
	closedir(directorie);
	handle_recursive(list, options);
}
