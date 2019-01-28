/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:35:52 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/21 19:35:55 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	set_filetype(t_file *file)
{
	/* PROBLEME ICI */
	if (S_IFSOCK & file->infos->st_mode)
		return ('s');
	else if (S_IFLNK & file->infos->st_mode)
		return ('l');
	else if (S_IFDIR & file->infos->st_mode)
		return ('d');
	else if (S_IFCHR & file->infos->st_mode)	
		return ('c');
	else if (S_IFIFO & file->infos->st_mode)
		return ('p');
	else if (S_IFBLK & file->infos->st_mode)
		return ('b');
	return ('-');
}

char	*read_permissions(t_file *file)
{
	char *str;

	if (!(str = ft_strnew(10)))
		return (NULL);
	str[0] = set_filetype(file);

	return (str);
}

int		read_long_format(t_file *file, t_command *command)
{
	if (command) {

	}
	ft_printf("%s  %s\n", read_permissions(file), file->name);
	return (1);
}

int		read_file(t_file *file, t_command *command)
{
	if (!has_option(command->options, 'a') && file->name[0] == '.')
		return (1);
	if (!has_option(command->options, 'l'))
		ft_printf("%s\n", file->name);
	else
		read_long_format(file, command);
	return (1);
}
