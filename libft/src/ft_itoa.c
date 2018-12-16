/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 13:28:57 by befuhro      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:28:58 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


static int	ft_size_string(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static long	decimal(int n)
{
	long dec;

	dec = 1;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		dec *= 10;
	}
	dec /= 10;
	return (dec);
}

static char	*ft_special(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

char		*ft_itoa(int n)
{
	int		i;
	long	dec;
	int		size_string;
	char	*dst;

	i = 0;
	dec = decimal(n);
	if (n == 0 || n == -2147483648)
		return (ft_special(n));
	size_string = ft_size_string(n);
	if (!(dst = ft_strnew(size_string)))
		return (0);
	if (n < 0)
	{
		dst[i] = '-';
		i++;
		n *= -1;
	}
	while (i < size_string)
	{
		dst[i++] = (n / dec) + '0';
		n %= dec;
		dec /= 10;
	}
	return (dst);
}
