/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ldaveau <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:20:06 by ldaveau      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 21:25:20 by ldaveau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                       
 *                       /                   */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int stock_option(char *av)
{
	int byte;

	byte = 0;
	if (is_under_s(av) == 1)
	{
		byte = (ft_strchr(av, 't')) ? byte + B_TIME : byte;
		byte = (ft_strchr(av, 'R')) ? byte + B_REC : byte;
		byte = (ft_strchr(av, 'r')) ? byte + B_REV : byte;
		byte = (ft_strchr(av, 'a')) ? byte + B_ALL : byte;
		byte = (ft_strchr(av, 'l')) ? byte + B_LIST : byte;
	}
	return (byte);
}

/*
void    create_options_byte(char *options, int *byte)
{
     if (!(*byte & B_TIME))
          *byte = (strchr(options, 't')) ? *byte + B_TIME : *byte;
      if (!(*byte & B_REC))
          *byte = (strchr(options, 'R')) ? *byte + B_REC : *byte;
      if (!(*byte & B_REV))
          *byte = (strchr(options, 'r')) ? *byte + B_REV : *byte;
      if (!(*byte & B_ALL))
          *byte = (strchr(options, 'a')) ? *byte + B_ALL : *byte;
      if (!(*byte & B_TIME))
          *byte = (strchr(options, 'l')) ? *byte + B_LIST : *byte;
}


/*
int   *get_option(char **av, int ac)
{
	int i;
	int *options;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	while (i++ < ac)
	{
		while (*av[i])
		{
			if (av[i][j] == '-')
			{
				while (av[i][j++] == 't' || av[i][j++] == 'R' ||
						av[i][j++] == 'r' ||
						av[i][j++] == 'a' || av[i][j++] == 'l')
				{
					options[k] = stock_option(av[i]);
					k++;
				}
			}
		}
	}
	return (options);
}
*/
int		is_under_s(char *av)
{
	int i;

	i = 0
	if (av[i] == '-' && (av[i + 1] == 't' || av[i + 1] == 'R' ||
	av[i + 1] == 'r' || av[i + 1] == 'a' || av[i + 1] == 'l'))
		return (1);
	if (av[i] == '-' && av[i + 1] == '-' && (av[i + 2] == 't' ||
	av[i + 2] == 'R' || av[i + 2] == 'r' || av[i + 2] == 'a' ||
	av[i + 2] == 'l'))
		return (1);
	else
		return (0);
}
/*
void	parser(char **av, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i++ < ac)
	{
		while (av[i])
		{
			while (av[i][j++])
			{
				if (is_under_s(av, i, j) == 1)
					get_option(av, ac);
			}
		}
	}
}


*/
int		index_for_path(char **av, int ac)
{
	int i;
	
	//int options;
	int *options;
	int j;
	struct stat buf;

	i = 0;
	j = 0;
	while (*av[i] && ac > i)
	{
		while (is_under_s(av[i]) == 1 && (lstat(av[i], &buf) == -1))
		//while (av[i][0] == '-' && (lstat(av[i], &buf) == -1))
		{
			options[j] = stock_option(av[i]);
			//create_options_byte(av[i, &options)
			j++;
			i++;
		}
		else
			return (i);
	}
	return (0);
}
