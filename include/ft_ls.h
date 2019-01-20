/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 23:43:45 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 14:57:47 by ldaveau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#include "../libft/include/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define B_TIME	1
#define B_REC	2
#define B_REV	4
#define B_ALL	8
#define B_LIST	16
#define B_MULTI	32

typedef struct		t_command
{
	int				options;
	char			**paths;
}					s_command;

typedef struct		t_file
{
	char			name[256];
	char			symlink[1024];
	time_t			mtime;
	blkcnt_t		blocks;
	nlink_t			links;
	mode_t			mode;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct stat     *stat;
	struct dirent	*info;
	struct t_file	*left;
	struct t_file	*right;
}					s_file;

typedef	struct		t_path
{
	char			*path;
	time_t			mtime;
	struct t_path	*left;
	struct t_path	*right;

}					s_path;

void	handle_file(char *file, int options);
void 	list_dir(int options, DIR *repository, char *path);
void    append_recursive_tree(char *path, s_path **list, int options);
char 	*append_path(char *s1, char *s2);
void    handle_path(char *path, int options);
void    handle_paths(char **paths, int options);
void    handle_args(char **args, int options);
void    print(s_file *files, int options);
void    dealloc_tree(s_file *files);
void    dealloc_recursive_list(s_path *list);
void 	handle_recursive(s_path *list, int options);
void    place_file(int options, s_file file, s_file **files, char *path);
s_file  *run_through_dir(int options, DIR *directorie, char *path, s_path **list);

#endif
