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


void	handle_command(char *path, int options)
{
	DIR *directorie;

	if ((directorie = opendir(path)) == NULL)
		perror("Permission denied.");
	else
	{
		list_dir(options, directorie, path);
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
		handle_command(av[2], options);
	return (0);
}
