/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:40:59 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:40:59 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!(dst = ft_strnew(len)) || !s || !*s)
		return (0);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
