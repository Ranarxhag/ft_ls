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


