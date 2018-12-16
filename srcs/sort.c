#include "ft_ls.h"

void	insert_file(int options, s_file **files, s_file *file)
{
	if (*files == NULL)
		*files = file;
	else
	{
		if ((*files)->info->d_type > file->info->d_type)
			insert_file(options, &(*files)->right, file);
		else
			insert_file(options, &(*files)->left, file);
	}
	(void)options;
}

s_file	*generate_file(struct dirent *info)
{
	s_file *file;

	file = (s_file*)malloc(sizeof(s_file));
	file->left = NULL;
	file->right = NULL;
	file->info = info;
	lstat(info->d_name, file->stat);
	return (file);
}

void	place_file(int options, struct dirent *info, s_file **files)
{
	s_file *file;

	file = generate_file(info);
	insert_file(options, files, file);
}

void	print_tree(s_file *files)
{
	if (files != NULL)
	{
		printf("type: %i\tname: %s\n", files->info->d_type, files->info->d_name);
		print_tree(files->left);
		print_tree(files->right);
	}
}

void	sort(int options, DIR *repository, char *path)
{
	s_file	*files;
	struct	dirent *info;
	s_path_link *list;

	list = NULL;
	files = NULL;
	while ((info = readdir(repository)))
	{
		if (info->d_name[0] != '.')
		{
			place_file(options, info, &files);
			if ((info->d_type == 4 || info->d_type == 0) && R_CHECK(options))
				append_recursive_list(append_path(path, info->d_name), &list);
		}
	}
	print_tree(files);
	if (list != NULL)
	{
		while (list != NULL)
		{
			printf("\n\n%s:\n", list->path);
			list_dir(list->path, options);
			list = list->next;
		}
	}
}
