/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:27:16 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/15 18:27:17 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*add_paths(int argc, char **argv, int i)
{
	t_file		*paths;
	struct stat fileinfo;

	paths = NULL;
	while (i < argc)
	{
		if (stat((const char*)argv[i], &fileinfo) == -1)
		{
			no_such_file_or_directory(argv[i]);
			if (ft_strequ("", argv[i]))
				return (NULL);
			i++;
			continue ;	
		}
		add_file_last(&(paths), new_file(argv[i], fileinfo.st_mtime));
		i++;
	}
	return (paths);
}

void			set_default_order(int argc, char **argv, int i)
{
	int		is_ordered;
	int		index;
	char	*tmp;

	is_ordered = 0;
	index = i;
	while (!is_ordered)
	{
		is_ordered = 1;
		index = i;
		while (index + 1 < argc)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
			{
				tmp = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = tmp;
				is_ordered = 0;
			}
			index++;
		}
	}
}

t_file			*set_paths(char *options, int argc, char **argv, int i)
{
	t_file *paths;
	
	set_default_order(argc, argv, i);
	if (!(paths = add_paths(argc, argv, i)))
		return (NULL);
	if (options)
	{

	}
	set_file_order(paths, options);
	return (paths);
}
