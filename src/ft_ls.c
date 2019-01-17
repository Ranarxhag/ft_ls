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

int		main(int argc, char **argv)
{
	t_command 	*command;
	t_file		*paths;
	//int i;

	if (!(command = set_command(argc, argv)))
		exit(EXIT_FAILURE);
	paths = command->paths;
	//i = 0;
	/*
	if (ft_array_length(command->paths) == 0)
		read_dir(".", command->options);
	else
	{
		while (command->paths[i])
		{
			read_dir(command->paths[i], command->options, );
			i++;
		}
	}
	read_dir(command);
	*/











	printf("---- OPTIONS ----\n%s\n", command->options);
	printf("\n---- PATHS ----\n");
	
	while (paths)
	{
		printf("%s\n", paths->name);
		paths = paths->next;
	}
	delete_command(command);
} 
