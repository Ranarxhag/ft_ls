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

static void	set_options(char *str, char *opt)
{
	int i;

	i = 1;
	while (opt[i])
	{
		if (ft_strchr((const char*)ALLOWED_OPTIONS, opt[i]) &&
			!(ft_strchr((const char*)str, opt[i])))
			ft_strncpy((const char*)&(str[ft_strlen(str)]), &(opt[i]), 1);
		i++;
	}
}

t_config	*set_config(int argc, char **argv)
{
	int i;
	t_config *config;

	if (!(config = (t_config*)malloc(sizeof(t_config*))))
		return (NULL);
	if (!(config->options = ft_strnew(ft_strlen(ALLOWED_OPTIONS))))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			set_options(config->options, argv[i]);
		i++;
	}

	return (config);
}