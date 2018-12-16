/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:31:54 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:31:55 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
			return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
		i++;
	}
	return (0);
}
