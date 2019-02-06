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

static t_file	*delete_paths(t_file *paths)
{
	t_file *tmp;

	if (paths == NULL)
		return (NULL);
	tmp = NULL;
	while (paths)
	{
		if (tmp != NULL)
			ft_memdel((void**)&tmp);
		tmp = paths;
		paths = paths->next;
	}
	ft_memdel((void**)&tmp);
	return (NULL);
}

static t_file	*add_current_path()
{
	t_file		*paths;
	struct stat *fileinfo;

	paths = NULL;
	fileinfo = NULL;
	if (!(fileinfo = malloc(sizeof(*fileinfo))))
		return (NULL);
	if (lstat(".", fileinfo) == -1)
	{
		no_such_file_or_directory(".");
		return (NULL);
	}
	add_file_last(&paths, new_file(".", fileinfo));

	return (paths);
}

static t_file	*add_paths(int argc, char **argv, char *options, int i)
{
	t_file		*paths;
	struct stat *fileinfo;

	paths = NULL;
	fileinfo = NULL;
	if (i >= argc)
		return (add_current_path());
	while (i < argc)
	{
		if (!(fileinfo = malloc(sizeof(*fileinfo))))
			return (NULL);
		if (lstat((const char*)argv[i], fileinfo) == -1)
		{
			no_such_file_or_directory(argv[i]);
			if (ft_strequ("", argv[i]))
				return (delete_paths(paths));
			add_file_last(&(paths), new_file(argv[i++], NULL));
			continue ;	
		}
		if (S_ISLNK(fileinfo->st_mode) && !has_option(options, 'l'))
			stat((const char*)argv[i], fileinfo);
		add_file_last(&(paths), new_file(argv[i], fileinfo));
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
	if (!(paths = add_paths(argc, argv, options, i)))
		return (NULL);
	set_file_order(paths, options);
	return (paths);
}
