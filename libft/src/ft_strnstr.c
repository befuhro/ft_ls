/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:41:08 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:41:09 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while ((i < len) && haystack[i])
	{
		if (haystack[i + j] == needle[j] && i + j < len)
		{
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return (((char*)haystack) + (i));
			}
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}
