#include "ft_ls.h"

void	print(s_file *files)
{
	if (files != NULL)
	{
		print(files->left);
		ft_putendl(files->name);
		print(files->right);
	}
}
