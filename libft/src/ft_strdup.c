/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:36:18 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:36:18 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char		*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
