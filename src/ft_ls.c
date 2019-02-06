/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:10:12 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/11 08:10:13 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		read_arg_dir(t_file *paths, t_command *command, int newline)
{
	t_file 	*tmp;

	tmp = paths;
	while (tmp)
	{
		if (tmp->infos && S_ISDIR(tmp->infos->st_mode))
		{
			if (!(read_directory(tmp->name, command, newline,
				count_files(paths))))
				return (-1);
			if (newline == 0)
				newline++;
		}
		tmp = tmp->next;
	}

	return (1);
}

int		read_args_files(t_file *paths, t_command *command)
{
	t_file		*tmp;
	int			count;
	t_column	*clength;
	char		*dirname;

	count = 0;
	tmp = paths;
	dirname = NULL;
	if (!(clength = set_columns_length(tmp, command, 1)))
		return (-1);
	while (tmp)
	{
		if (tmp->infos && !S_ISDIR(tmp->infos->st_mode))
		{
			read_file(tmp, command, ".", clength);
			count++;
		}
		tmp = tmp->next;
	}
	return (count);
}

int		read_args(t_file *paths, t_command *command)
{
	int		newline;

	if (paths == NULL)
	{
		read_directory(".", command, 0, 0);
		return (1);
	}
	if ((newline = read_args_files(paths, command)) == -1)
		return (-1);
	if (read_arg_dir(paths, command, newline > 0 ? 1 : 0) == -1)
		return (-1);
	delete_command(command);
	return (1);
}

int		main(int argc, char **argv)
{
	t_command 	*command;

	if (!(command = set_command(argc, argv)))
		exit(EXIT_FAILURE);
	if ((read_args(command->paths, command)) == -1)
	{
		delete_command(command);
		exit(EXIT_FAILURE);
	}
} 
