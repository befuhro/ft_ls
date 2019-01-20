/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 02:08:22 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 17:21:05 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_rights(mode_t mode)
{
	char s[11];

	ft_bzero(s, 11);
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
	s[3] = mode & S_ISUID && mode & S_IXUSR ? 's' : s[3];
	s[3] = mode & S_ISUID && !(mode & S_IXUSR) ? 'S' : s[3];
	s[6] = mode & S_ISGID && mode & S_IXGRP ? 's' : s[6];
	s[6] = mode & S_ISGID && !(mode & S_IXGRP) ? 'S' : s[6];
	s[9] = mode & S_ISVTX && mode & S_IXOTH ? 't' : s[9];
	s[9] = mode & S_ISVTX && !(mode & S_IXOTH) ? 'T' : s[9];
	ft_putstr(s);
}

void	l_display(s_file *file)
{
	struct group	*grp;
	struct passwd	*pwd;

	pwd = NULL;
	grp = NULL;
	pwd = getpwuid(file->uid);
	grp = getgrgid(file->gid);
	print_rights(file->mode);
	ft_putchar('\t');
	ft_putnbr(file->links);
	ft_putchar(' ');
	if (pwd != NULL)
		ft_putstr(pwd->pw_name);
	else
		ft_putnbr(file->uid);
	ft_putchar('\t');
	if (grp != NULL)
		ft_putstr(grp->gr_name);
	else
		ft_putnbr(file->gid);
	ft_putchar('\t');
	ft_putnbr(file->size);
	ft_putchar('\t');
	write(1, ctime(&file->mtime) + 4, 12);
	ft_putchar('\t');
	ft_putstr(file->name);
	if (file->symlink[0] != 0)
	{
		ft_putstr(" -> ");
		ft_putstr(file->symlink);
	}
	ft_putchar('\n');
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
