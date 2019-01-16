#include "ft_ls.h"

char *append_path(char *s1, char *s2)
{
	char *s;

	if (s1[ft_strlen(s1) - 1] != '/')
	{
		s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
		ft_memset(s,'\0', ft_strlen(s1) + ft_strlen(s2) + 2);
		ft_strcpy(s, s1);
		s[ft_strlen(s1)] = '/';
		ft_strcpy(&s[ft_strlen(s1) + 1], s2);
	}
	else
	{
		s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		ft_memset(s,'\0', ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strcpy(s, s1);
		ft_strcpy(&s[ft_strlen(s1)], s2);
	}
	return (s);
}

void	insert_recursive_node(s_path *node, s_path **list, int options)
{
	if (*list == NULL)
		*list = node;
	else
	{
		if (options & B_TIME)
		{
			 if ((*list)->mtime > node->mtime ||
				 ((*list)->mtime == node->mtime &&
			      ft_strcmp((*list)->path, node->path) < 0))
		       insert_recursive_node(node, &(*list)->right, options);
			else
	   			insert_recursive_node(node, &(*list)->left, options);
		}
		else
		{
			if (ft_strcmp((*list)->path, node->path) < 0)
				insert_recursive_node(node, &(*list)->right, options);
			else
				insert_recursive_node(node, &(*list)->left, options);
		}
	}
}

void    append_recursive_tree(char *path, s_path **list, int options)
{
	s_path	*node;

	struct stat *stat;
	if (ft_strcmp(path, ".") && ft_strcmp(path, ".."))
	{	
		node = malloc(sizeof(s_path));
		node->path = ft_strdup(path); 
		node->left = NULL;
		node->right = NULL;
		if (options & B_TIME)
		{
			stat = malloc(sizeof(struct stat));
			lstat(path, stat);
			node->mtime = stat->st_mtime;
			free(stat);
		}
		insert_recursive_node(node, list, options);
	}
}

void	handle_recursive(s_path *list, int options)
{
	if (list != NULL)
	{
		if (options & B_REV)
		{
			handle_recursive(list->right, options);
			handle_command(list->path, options);
			handle_recursive(list->left, options);
		}
		else
		{
			handle_recursive(list->left, options);
			handle_command(list->path, options);
			handle_recursive(list->right, options);
		}
		ft_strdel(&list->path);
		free(list);
	}	
}
