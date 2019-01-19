/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_file.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 02:12:41 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 02:27:02 by befuhro     ###    #+. /#+    ###.fr     */
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
		if (options & B_TIME)
		{
			if ((*files)->mtime > file->mtime ||
					((*files)->mtime == file->mtime &&
					 ft_strcmp((*files)->name, file->name) < 0))
				insert_file(options, &(*files)->right, file);
			else
				insert_file(options, &(*files)->left, file);
		}
		else
		{
			if (ft_strcmp((*files)->name, file->name) < 0)
				insert_file(options, &(*files)->right, file);
			else
				insert_file(options, &(*files)->left, file);
		}
	}
}

s_file	*generate_file(s_file file)
{
	s_file *node;

	node = malloc(sizeof(s_file));
	node->left = NULL;
	node->right = NULL;
	node->info = file.info;
	node->stat = file.stat;
	node->mtime = file.stat->st_mtime;
	node->mode = file.stat->st_mode;
	node->uid = file.stat->st_uid;
	node->gid = file.stat->st_gid;
	node->size = file.stat->st_size;
	node->links = file.stat->st_nlink;
	node->blocks = file.stat->st_blocks;
	ft_strcpy(node->name, file.info->d_name);
	return (node);
}

void	place_file(int options, s_file file, s_file **files)
{
	s_file *link_file;

	link_file = generate_file(file);
	insert_file(options, files, link_file);
}
