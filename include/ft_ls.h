#ifndef FT_LS_H
#define FT_LS_H
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

#define B_TIME	1
#define B_REC	2
#define B_REV	4
#define B_ALL	8
#define B_LIST	16

typedef struct		t_command
{
	int				options;
	char			**paths;
}					s_command;

typedef struct		t_file
{
	char			name[256];
	time_t				mtime;
	mode_t				mode;
	struct dirent	*info;
	struct stat		*stat;
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

void 	list_dir(int options, DIR *repository, char *path);
void    append_recursive_tree(char *path, s_path **list, int options);
char 	*append_path(char *s1, char *s2);
void    handle_command(char *path, int options);
void    print(s_file *files, int options);
void    dealloc_tree(s_file *files);
void    dealloc_recursive_list(s_path *list);
void 	handle_recursive(s_path *list, int options);
s_file  *run_through_dir(int options, DIR *directorie, char *path, s_path **list);

#endif
