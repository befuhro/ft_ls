/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:31:06 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:31:06 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if (!(elem = (t_list*)ft_memalloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		elem->content_size = 0;
		elem->content = NULL;
	}
	else
	{
		if (!(elem->content = (void*)ft_memalloc(sizeof(content_size))))
			return (0);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
