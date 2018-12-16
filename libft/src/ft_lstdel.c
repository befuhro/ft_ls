/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:29:47 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:29:48 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_to_del;

	while (*alst)
	{
		next_to_del = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = next_to_del;
	}
	*alst = NULL;
}
