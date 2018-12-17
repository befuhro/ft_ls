#ifndef FT_LS_H
#define FT_LS_H
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

#define T_BITE (1 << 0)
#define R_BITE (1 << 1)
#define S_BITE (1 << 2)
#define A_BITE (1 << 3)

#define T_CHECK(x) (x & (1 << 0)) >> 0
#define R_CHECK(x) (x & (1 << 1)) >> 1
#define S_CHECK(x) (x & (1 << 2)) >> 2
#define A_CHECK(x) (x & (1 << 3)) >> 3

typedef struct		t_command
{
	int				options;
	char			**paths;
}					s_command;

typedef struct		t_file
{
	char			name[256];
	struct dirent	*info;
	struct stat		*stat;
	struct t_file	*left;
	struct t_file	*right;
}					s_file;

typedef	struct		t_path
{
	char			*path;
	struct t_path	*left;
	struct t_path	*right;

}					s_path;

void 	list_dir(int options, DIR *repository, char *path);
void    append_recursive_tree(char *path, s_path **list, int options);
char 	*append_path(char *s1, char *s2);
void    handle_command(char *path, int options);
void    print(s_file *files);
void    dealloc_tree(s_file *files);
void    dealloc_recursive_list(s_path *list);
void 	handle_recursive(s_path *list, int options);

#endif
