#include "ft_ls.h"

void	dealloc_tree(s_file *files)
{
	if (files != NULL)
	{
		dealloc_tree(files->left);
		dealloc_tree(files->right);
		free(files);
	}
}
