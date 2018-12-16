/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:40:18 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:40:19 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
