/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:39:57 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:39:58 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = 0;
	if (s && f)
	{
		if (!(dst = ft_strnew(ft_strlen(s))))
			return (0);
		while (s[i])
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
