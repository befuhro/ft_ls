/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dealloc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ldaveau <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 12:22:35 by ldaveau      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 22:17:23 by befuhro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	dealloc_tree(t_file *files)
{
	if (files != NULL)
	{
		dealloc_tree(files->left);
		dealloc_tree(files->right);
		free(files);
	}
}
