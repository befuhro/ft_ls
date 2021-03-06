/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_file.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 02:12:41 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:18:49 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_file(int options, t_file **files, t_file *file)
{
	if (*files == NULL)
		*files = file;
	else
	{
		if (options & B_TIME)
		{
			if ((*files)->mtime > file->mtime || ((*files)->mtime == file->mtime
						&& ft_strcmp((*files)->name, file->name) < 0))
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

t_file	*generate_file(t_file file, char *path)
{
	t_file *node;

	if (!(node = malloc(sizeof(t_file))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->info = file.info;
	node->stat = file.stat;
	if (S_ISCHR(file.stat->st_mode) || S_ISBLK(file.stat->st_mode))
	{
		node->major = major(file.stat->st_rdev);
		node->minor = minor(file.stat->st_rdev);
	}
	node->mtime = file.stat->st_mtime;
	node->mode = file.stat->st_mode;
	node->uid = file.stat->st_uid;
	node->gid = file.stat->st_gid;
	node->size = file.stat->st_size;
	node->links = file.stat->st_nlink;
	node->blocks = file.stat->st_blocks;
	ft_strcpy(node->name, file.info->d_name);
	ft_bzero(node->symlink, 1024);
	readlink(path, node->symlink, 1023);
	return (node);
}

void	place_file(int options, t_file file, t_file **files, char *path)
{
	t_file *link_file;

	link_file = generate_file(file, path);
	insert_file(options, files, link_file);
}

void	handle_file(char *path, int options)
{
	t_file file;
	t_file *ptr;

	if (!(file.info = malloc(sizeof(struct dirent))))
		return ;
	if (!(file.stat = malloc(sizeof(struct stat))))
		return ;
	lstat(path, file.stat);
	ft_strcpy(file.info->d_name, path);
	ptr = generate_file(file, path);
	print(ptr, options);
	free(file.info);
	free(file.stat);
	free(ptr);
}
