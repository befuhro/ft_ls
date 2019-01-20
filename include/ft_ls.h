/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 22:22:17 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:22:58 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

# define B_TIME	1
# define B_REC	2
# define B_REV	4
# define B_ALL	8
# define B_LIST	16
# define B_MULTI	32

typedef struct		s_command
{
	int				options;
	char			**paths;
}					t_command;

typedef struct		s_file
{
	char			name[256];
	char			symlink[1024];
	time_t			mtime;
	unsigned int	major;
	unsigned int	minor;
	blkcnt_t		blocks;
	nlink_t			links;
	mode_t			mode;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct stat		*stat;
	struct dirent	*info;
	struct s_file	*left;
	struct s_file	*right;
}					t_file;

typedef	struct		s_path
{
	char			*path;
	time_t			mtime;
	struct s_path	*left;
	struct s_path	*right;

}					t_path;

char				**sort_paths(int size, char **args, int options);
void				handle_file(char *file, int options);
void				list_dir(int options, DIR *repository, char *path);
void				append_recursive_tree(char *path, t_path **list,
		int options);
char				*append_path(char *s1, char *s2);
void				handle_path(char *path, int options);
void				handle_paths(char **paths, int options);
void				handle_args(char **args, int options, int length_array);
void				print(t_file *files, int options);
void				dealloc_tree(t_file *files);
void				dealloc_recursive_list(t_path *list);
void				handle_recursive(t_path *list, int options);
void				place_file(int options, t_file file, t_file **files,
		char *path);
t_file				*run_through_dir(int options, DIR *directorie,
		char *path, t_path **list);

#endif
