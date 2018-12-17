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

void    append_recursive_list(char *path, s_path_link **list)
{
	s_path_link *elt;
	s_path_link *tmp;

	if (ft_strcmp(path, ".") && ft_strcmp(path, ".."))
	{
		elt = (s_path_link*)malloc(sizeof(s_path_link) * 1);
		elt->path = ft_strdup(path);
		elt->next = NULL;
		if (*list == NULL)
			*list = elt;
		else {
			tmp = *list;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = elt;
		}
	}
}

void	handle_recursive(s_path_link **list, int options)
{
	s_path_link *tmp;

	tmp = NULL;
	while ((*list) != NULL)
	{
		handle_command((*list)->path, options);
		tmp = *list;
		*list = (*list)->next;
		ft_strdel(&tmp->path);
		free(tmp);
	}
}
