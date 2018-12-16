/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:31:27 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:31:28 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (dest + (i + 1));
		i++;
	}
	return (NULL);
}
