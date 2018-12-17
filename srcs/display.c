#include "ft_ls.h"

void	print(s_file *files, int options)
{
	if (files != NULL)
	{
		if (r_CHECK(options))
		{
			print(files->right, options);
			ft_putendl(files->name);
			print(files->left, options);
		}
		else
		{
			print(files->left, options);
			ft_putendl(files->name);
			print(files->right, options);
		}
	}
}
