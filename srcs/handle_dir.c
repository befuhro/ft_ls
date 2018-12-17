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
	return (link_file);
}

void	place_file(int options, s_file file, s_file **files)
{
	s_file *link_file;

	link_file = generate_file(file);
	insert_file(options, files, link_file);
}

s_file	*run_through_dir(int options, DIR *directorie, char *path, s_path_link **list)
{
	s_file	*files;
	s_file	file;	
	char	*tmp_path;

	files = NULL;
	tmp_path = NULL;
	while ((file.info = readdir(directorie)))
	{
		tmp_path = append_path(path, file.info->d_name);
		file.stat = (struct stat*)malloc(sizeof(struct stat));
		lstat(tmp_path, file.stat);
		if (file.info->d_name[0] != '.')
		{
			place_file(options, file, &files);
			if (S_ISDIR(file.stat->st_mode) && R_CHECK(options))
				append_recursive_list(tmp_path, list);
		}
		ft_strdel(&tmp_path);
		free(file.stat);
	}
	return (files);
}

void	list_dir(int options, DIR *directorie, char *path)
{
	s_file	*files;
	s_path_link *list;

	list = NULL;
	files = run_through_dir(options, directorie, path, &list);
	print(files);
	dealloc_tree(files);
	closedir(directorie);
	handle_recursive(&list, options);
}
