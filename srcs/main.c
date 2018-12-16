#include "ft_ls.h"
#include <errno.h>

int	 create_options_byte(char *options)
{
	int byte;

	byte = 0;
	byte = (ft_strchr(options, 't')) ? byte + T_BITE : byte;
	byte = (ft_strchr(options, 'R')) ? byte + R_BITE : byte;
	byte = (ft_strchr(options, 's')) ? byte + S_BITE : byte;
	byte = (ft_strchr(options, 'a')) ? byte + A_BITE : byte;
	return (byte);
}


void	list_dir(char *path, int options)
{
	DIR *repository;



	if ((repository = opendir(path)) == NULL)
	{
		perror("Cannot open .");
	}
	else
	{
		sort(options, repository, path);
		closedir(repository);
	}
}

int		main(int ac, char **av)
{
	int options;
	(void)ac;
	if (av[1] != NULL)
		options = create_options_byte(av[1]);
	else
		options = 0;
	if (ac >= 2)
		list_dir(av[2], options);
	return (0);
}
