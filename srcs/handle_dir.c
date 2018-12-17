/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_dir.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 19:48:14 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 21:05:42 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_file(int options, s_file **files, s_file *file)
{
	if (*files == NULL)
		*files = file;
	else
	{
		if (ft_strcmp((*files)->info->d_name, file->info->d_name) > 0)
		{
			//printf("%s < %s\n" , file->info->d_name, (*files)->info->d_name);
			insert_file(options, &(*files)->left, file);
		}
		else
		{
			//printf("%s > %s\n" , file->info->d_name, (*files)->info->d_name);
			insert_file(options, &(*files)->right, file);
		}
	}
	(void)options;
}

s_file	*generate_file(s_file file)
{
	s_file *link_file;

	link_file = (s_file*)malloc(sizeof(s_file));
	link_file->left = NULL;
	link_file->right = NULL;
	link_file->info = file.info;
	link_file->stat = file.stat;
	ft_strcpy(link_file->name, file.info->d_name);
	return (link_file);
}

void	place_file(int options, s_file file, s_file **files)
{
	s_file *link_file;

	link_file = generate_file(file);
	insert_file(options, files, link_file);
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
		file.stat = (struct stat*)malloc(sizeof(struct stat));
		lstat(entire_path, file.stat);
		if (file.info->d_name[0] != '.' || 
			(A_CHECK(options) && ft_strcmp(file.info->d_name, ".") &&
			 ft_strcmp(file.info->d_name, "..")))
		{
			place_file(options, file, &files);
			if (S_ISDIR(file.stat->st_mode) && R_CHECK(options))
				append_recursive_tree(entire_path, list, options);
		}
		ft_strdel(&entire_path);
		free(file.stat);
	}
	return (files);
}
