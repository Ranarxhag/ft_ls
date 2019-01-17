/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:27:11 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/15 18:27:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_options(char *str, char **argv, int *i)
{
	int j;

	j = 1;
	while (argv[*i][j])
	{
		if (!ft_strchr((const char*)ALLOWED_OPTIONS, argv[*i][j]))
		{
			illegal_option(argv[*i][j]);
			return (0);
		}

		if (!(ft_strchr((const char*)str, argv[*i][j])))
			ft_strncpy(&(str[ft_strlen(str)]), (const char*)&(argv[*i][j]), 1);
		j++;
	}
	return (1);
}

char		*set_options(int argc, char **argv, int *i)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(ALLOWED_OPTIONS))))
		return (NULL);
	while (*i < argc)
	{
		if (ft_strequ(argv[*i], "--"))
		{
			(*i)++;
			break ;
		}
		if (argv[*i][0] != '-' || ft_strequ(argv[*i], "-"))
			break ;
		if (!add_options(str, argv, i))
		{
			ft_strdel(&(str));
			return (NULL); 
		}
		
		(*i)++;
	}
	return (str);
}
