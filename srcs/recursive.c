#include "ft_ls.h"

char *append_path(char *s1, char *s2)
{
	char *s;
	int i;

	i = 0;
	s = (char*)malloc(sizeof(char) * (ft_strlen(s1)) + ft_strlen(s2) + 2);
	ft_memset(s,'\0', sizeof(s));
	ft_strcpy(s, s1);
	while (s[i])
		i++;
	s[i] = '/';
	i++;
	ft_strcpy(&s[i], s2);
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
