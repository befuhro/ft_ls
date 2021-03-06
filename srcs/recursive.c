/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recursive.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 23:25:50 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:19:27 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*append_path(char *s1, char *s2)
{
	char *s;

	if (s1[ft_strlen(s1) - 1] != '/')
	{
		if (!(s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
			return (NULL);
		ft_memset(s, '\0', ft_strlen(s1) + ft_strlen(s2) + 2);
		ft_strcpy(s, s1);
		s[ft_strlen(s1)] = '/';
		ft_strcpy(&s[ft_strlen(s1) + 1], s2);
	}
	else
	{
		if (!(s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_memset(s, '\0', ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strcpy(s, s1);
		ft_strcpy(&s[ft_strlen(s1)], s2);
	}
	return (s);
}

void	insert_recursive_node(t_path *node, t_path **list, int options)
{
	if (*list == NULL)
		*list = node;
	else
	{
		if (options & B_TIME)
		{
			if ((*list)->mtime > node->mtime || ((*list)->mtime == node->mtime
						&& ft_strcmp((*list)->path, node->path) < 0))
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

void	append_recursive_tree(char *path, t_path **list, int options)
{
	t_path		*node;
	struct stat	*stat;

	if (ft_strcmp(path, ".") && ft_strcmp(path, ".."))
	{
		if (!(node = malloc(sizeof(t_path))))
			return ;
		node->path = ft_strdup(path);
		node->left = NULL;
		node->right = NULL;
		if (options & B_TIME)
		{
			if (!(stat = malloc(sizeof(struct stat))))
				return ;
			lstat(path, stat);
			node->mtime = stat->st_mtime;
			free(stat);
		}
		insert_recursive_node(node, list, options);
	}
}

void	handle_recursive(t_path *list, int options)
{
	if (list != NULL)
	{
		if (options & B_REV)
		{
			handle_recursive(list->right, options);
			handle_path(list->path, options);
			handle_recursive(list->left, options);
		}
		else
		{
			handle_recursive(list->left, options);
			handle_path(list->path, options);
			handle_recursive(list->right, options);
		}
		ft_strdel(&list->path);
		free(list);
	}
}
