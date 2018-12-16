/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_at.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:29:30 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:29:31 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


void	ft_lstadd_at(t_list *list, t_list *new, unsigned int index)
{
	t_list *adrr;

	adrr = (t_list*)malloc(sizeof(t_list));
	adrr->next = list[index - 1].next;
	list[index - 1].next = new;
	new->next = adrr->next;
	free(adrr);
}
