/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:41:16 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 21:48:05 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (((char*)haystack));
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return (((char*)haystack) + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
