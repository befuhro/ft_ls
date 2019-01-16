#include "ft_ls.h"

void	display_rights(mode_t mode)
{
	char s[12];

	ft_bzero(s, 12);
	s[0] = S_ISDIR(mode) ? 'd' : '-';
	s[1] = mode & S_IRUSR ? 'r' : '-';
	s[2] = mode & S_IWUSR ? 'w' : '-';
	s[3] = mode & S_IXUSR ? 'x' : '-';
	s[4] = mode & S_IRGRP ? 'r' : '-';
	s[5] = mode & S_IWGRP ? 'w' : '-';
	s[6] = mode & S_IXGRP ? 'x' : '-';
	s[7] = mode & S_IROTH ? 'r' : '-';
	s[8] = mode & S_IWOTH ? 'w' : '-';
	s[9] = mode & S_IXOTH ? 'x' : '-';
	ft_putstr(s);
}

void	l_display(s_file *file)
{
	display_rights(file->mode);
	ft_putchar('\t');
	ft_putendl(file->name);	
}

void	print(s_file *files, int options)
{
	if (files != NULL)
	{
		if (options & B_REV)
		{
			print(files->right, options);
			if (options & B_LIST)
				l_display(files);
			else
				ft_putendl(files->name);
			print(files->left, options);
		}
		else
		{
			print(files->left, options);
			if (options & B_LIST)
				l_display(files);
			else
				ft_putendl(files->name);
			print(files->right, options);
		}
	}
}
