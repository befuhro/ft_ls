/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:32:29 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:32:30 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			((char*)dst)[len] = ((const char*)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
