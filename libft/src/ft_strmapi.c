/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:39:49 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:39:50 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	if (s && f)
	{
		if (!(dst = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i])
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
