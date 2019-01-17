#include "ft_ls.h"

void	print_rights(mode_t mode)
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

void	print_size(off_t size)
{
	if (size < 1000)
	{
		ft_putnbr(size);
		ft_putchar('B');
	}
	else if (size < 1000000)
	{
		ft_putnbr(size / 1024);
		ft_putchar('K');
	}
	else if (size < 1000000000)
	{
		ft_putnbr(size / 1048576);
		ft_putchar('M');
	}
	else if (size < 1000000000000)
	{
		ft_putnbr(size / 1073741824);
		ft_putchar('M');
	}
	else
		ft_putnbr(size);
}

void	l_display(s_file *file)
{
	struct	group	*grp;
	struct	passwd	*pwd;

	pwd = getpwuid(file->uid);	
	grp = getgrgid(file->gid);	
	
	print_rights(file->mode);
	ft_putchar('\t');
	ft_putnbr(file->links);
	ft_putchar(' ');
	ft_putstr(pwd->pw_name);
	ft_putchar('\t');
	ft_putstr(grp->gr_name);
	ft_putchar('\t');
	ft_putnbr(file->size);
	ft_putchar('\t');
	write(1, file->date + 4, 12);
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
