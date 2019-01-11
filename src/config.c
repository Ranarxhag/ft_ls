/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:16:44 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/11 08:16:45 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		delete_config(t_lsconfig *config, int state)
{
	int i;

	i = 0;
	ft_strdel(&(config->options));
	free(config);
	config = NULL;
	return (state);
}

static int			is_valid_config(t_lsconfig *config)
{
	int i;

	i = 0;
	while (config->options[i])
	{
		if (!ft_strchr((const char*)ALLOWED_OPTIONS, config->options[i]))
		{
			ft_printf("ft_ls: illegal option -- %c\n"
					  "usage: ft_ls [-%s] [file ...]\n",
			config->options[i], ALLOWED_OPTIONS);
			return (delete_config(config, 0));
		}
		i++;
	}
	i = 0;
	while (config->paths[i])
	{
		if (ft_strequ(config->paths[i], "") == 1)
		{
			ft_printf("ft_ls: fts_open: No such file or directory\n");
			return (delete_config(config, 0));
		}
		i++;
	}
	return (1);
}

static void	add_paths(char **argv, int argc, int i, char **paths)
{
	int j;

	j = 0;
	while (i < argc)
	{
		paths[j] = argv[i];
		i++;
		j++;
	}
	paths[j] = NULL;
}

static void	add_options(char *str, char **argv, int *i, int argc)
{
	int j;

	j = 1;
	while (*i < argc)
	{
		if (argv[*i][0] != '-')
			break ;
		j = 1;
		while (argv[*i][j])
		{
			if (!(ft_strchr((const char*)str, argv[*i][j])))
				ft_strncpy(&(str[ft_strlen(str)]), (const char*)&(argv[*i][j]), 1);
			j++;
		}
		*i = *i + 1;
	}
}

t_lsconfig	*set_config(int argc, char **argv)
{
	int i;
	t_lsconfig *config;

	if (!(config = (t_lsconfig*)malloc(sizeof(t_lsconfig*))))
		return (NULL);
	if (!(config->options = ft_strnew(ft_strlen(ALLOWED_OPTIONS))))
	{
		free(config);
		return (NULL);
	}
	i = 1;
	add_options(config->options, argv, &i, argc);
	if (!(config->paths = (char**)malloc(sizeof(char*) * (argc - i))))
	{
		delete_config(config, 0);
		return (NULL);
	}
	add_paths(argv, argc, i, config->paths);
	if (!(is_valid_config(config)))
		return (NULL);
	return (config);
}
