/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:37:47 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/21 19:37:48 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_waiting	*delete_waiting(t_waiting **waiting)
{
	t_waiting *oldnext;

	oldnext = NULL;
	while (*waiting)
	{
		oldnext = (*waiting)->next;
		ft_memdel((void**)waiting);
		*waiting = oldnext;
	}
	*waiting = NULL;
	return (NULL);
}

int			read_directory(char *dirname, t_command *command, int newline,
							int	nb_paths)
{
	DIR 			*dirp;
	t_file			*files;
	t_waiting		*waiting;
	t_waiting		*tmpwait;

	if (dirname == NULL)
		return (-1);
	if (nb_paths > 1)
		ft_printf(newline ? "\n%s:\n" : "%s:\n", dirname);
	if (!(dirp = opendir(dirname)))
		return (error_opendir(dirname));
	if (!(files = store_files(dirname, dirp, command)))
		return (-1);
	waiting = NULL;
	closedir(dirp);
	if (read_files(files, dirname, &waiting, command) == -1)
		return (-1);
	delete_files(&files);
	tmpwait = waiting;
	while (tmpwait)
	{
		if (read_directory(tmpwait->path, command, 1, 2) == -1)
		{
			delete_waiting(&waiting);
			return (-1);
		}
		tmpwait = tmpwait->next;
	}
	delete_waiting(&waiting);
	return (1);
}
