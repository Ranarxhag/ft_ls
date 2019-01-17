/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:16:44 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/11 08:16:45 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		delete_command_paths(t_file **paths)
{
	if (!paths || !*paths)
		return ;
	while ((*paths)->next)
		delete_command_paths(&((*paths)->next));
	ft_memdel((void**)paths);
}

void			delete_command(t_command *command)
{
	ft_strdel(&(command->options));
	delete_command_paths(&(command->paths));
	ft_memdel((void**)&(command));
}

/*
static int		delete_command(t_command *command, int state)
{
	int i;

	i = 0;
	ft_strdel(&(command->options));
	free(command);
	command = NULL;
	return (state);
}

static int			is_valid_command(t_command *command)
{
	int i;

	i = 0;
	while (command->options[i])
	{
		if (!ft_strchr((const char*)ALLOWED_OPTIONS, command->options[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n"
					  "usage: ft_ls [-%s] [file ...]\n",
			command->options[i], ALLOWED_OPTIONS);
			return (delete_command(command, 0));
		}
		i++;
	}
	i = 0;
	while (command->paths[i])
	{
		if (ft_strequ(command->paths[i], "") == 1)
		{
			perror("ft_ls: ");
			ft_printf("ft_ls: fts_open: No such file or directory\n");
			return (delete_command(command, 0));
		}
		i++;
	}
	return (1);
}
*/

t_command		*set_command(int argc, char **argv)
{
	t_command *command;
	int i;

	i = 1;
	if (!(command = malloc(sizeof(*command))))
		return (NULL);
	if (!(command->options = set_options(argc, argv, &i)))
	{
		ft_memdel((void**)&(command));
		return (NULL);
	}
	if (!(command->paths = set_paths(command->options, argc, argv, i)))
	{
		delete_command(command);
		return (NULL);
	}
	return (command);
}


