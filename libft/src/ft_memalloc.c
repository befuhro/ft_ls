/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:31:14 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:31:15 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ret;

	i = 0;
	if (!(ret = (void*)malloc(sizeof(void) * size)))
		return (0);
	while (i < size)
	{
		((char*)ret)[i] = 0;
		i++;
	}
	return (ret);
}
