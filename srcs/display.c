/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 02:08:22 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 02:25:59 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
	write(1, ctime(&file->mtime) + 4, 12);
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
