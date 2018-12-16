/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:37:22 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:37:22 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;

	if (!s1 || !s2 || !(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	dst = ft_strcpy(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
