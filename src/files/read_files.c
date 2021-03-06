/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:20:56 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/23 15:20:57 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*delete_variables(struct stat **fileinfo, char **fullname)
{
	ft_strdel(fullname);
	ft_memdel((void**)fileinfo);
	return (NULL);
}

t_file	*delete_files(t_file **files)
{
	t_file *oldnext;

	oldnext = NULL;
	while (*files)
	{
		oldnext = (*files)->next;
		ft_memdel((void**)files);
		*files = oldnext;
	}
	files = NULL;
	return (NULL);
}

t_file	*store_files(char *dirname, DIR *dirp, t_command *command)
{
	t_file			*files;
	struct stat 	*fileinfo;
	char			*fullname;
	struct dirent	*dir;

	files = NULL;
	fileinfo = NULL;
	while ((dir = readdir(dirp)))
	{
		if (!has_option(command->options, 'a') && dir->d_name[0] == '.')
			continue ;
		if (!(fullname = ft_strjoin(ft_strjoin(dirname, "/"), dir->d_name)))
			return (delete_files(&files));
		if (!(fileinfo = malloc(sizeof(*fileinfo))))
			return (delete_variables(&fileinfo, &fullname));
		if (lstat(fullname, fileinfo) == -1)
		{
			no_such_file_or_directory(fullname);
			delete_variables(&fileinfo, &fullname);
			continue ;
		}
		add_file_last(&files, new_file(dir->d_name, fileinfo));
		ft_strdel(&fullname);
	}
	set_file_order(files, command->options);
	return (files);
}

void	push_waiting(t_file **tmp, char *dirname, t_waiting **waiting,
					t_command *command)
{
	if (has_option(command->options, 'R') && S_ISDIR((*tmp)->infos->st_mode)
			&& !ft_strequ((*tmp)->name, ".") && !ft_strequ((*tmp)->name, ".."))
	{
		if (!has_option(command->options, 'a') && (*tmp)->name[0] == '.')
		{
			*tmp = (*tmp)->next;
			return ;
		}
		add_waiting_last(waiting, new_waiting(
			ft_strjoin(ft_strjoin(dirname, "/"), (*tmp)->name)));
	}
}

int		read_files(t_file *files, char *dirname, t_waiting **waiting,
					t_command *command)
{
	t_file		*tmp;
	t_column	*clength;

	tmp = files;
	if (!(clength = set_columns_length(files, command, 0)))
		return (0);
	while (tmp)
	{
		if (!read_file(tmp, command, dirname, clength))
		{
			delete_waiting(waiting);
			delete_files(&files);
			return (-1);
		}
		push_waiting(&tmp, dirname, waiting, command);
		tmp = tmp->next;
	}
	ft_memdel((void**)&clength);
	return (1);
}
