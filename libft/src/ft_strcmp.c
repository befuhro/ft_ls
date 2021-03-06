/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:36:33 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 21:49:22 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned long i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (s1[i] != s2[i] && (s1[i] || s2[i]))
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}
