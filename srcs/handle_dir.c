/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_dir.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:14 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 04:55:02 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_total(s_file *file, int *total)
{
	if (file != NULL)
	{
		get_total(file->left, total);
		*total += file->blocks;
		get_total(file->right, total);
	}
}

s_file	*run_through_dir(int options, DIR *directorie, char *path, s_path **list)
{
	s_file	*files;
	s_file	file;	
	char	*entire_path;

	files = NULL;
	entire_path = NULL;
	while ((file.info = readdir(directorie)))
	{
		entire_path = append_path(path, file.info->d_name);
		file.stat = malloc(sizeof(struct stat));
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

void	list_dir(int options, DIR *directorie, char *path)
{
	s_file	*files;
	s_path *list;
	int total;

	total = 0;
	list = NULL;
	files = run_through_dir(options, directorie, path, &list);
	ft_putchar('\n');
	if (options & B_REC || options & B_MULTI)
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
