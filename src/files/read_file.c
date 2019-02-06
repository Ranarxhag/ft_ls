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

int		read_long_format(t_file *file, t_command *command, char *dirname,
	t_column *clength)
{
	struct passwd 	*pwd;
	struct group 	*grp;
	
	if (command || clength) {

	}
	pwd = getpwuid(file->infos->st_uid);
	grp = getgrgid(file->infos->st_gid);
	ft_printf("%-10s  %*d %-*s  %-*s", read_permissions(file), 
		clength->n_link, file->infos->st_nlink, clength->uname, pwd == NULL ? 
		ft_itoa(file->infos->st_uid) : pwd->pw_name, clength->gname,
		grp == NULL ? ft_itoa(file->infos->st_gid) : grp->gr_name);
	
	if (S_ISBLK(file->infos->st_mode) || S_ISCHR(file->infos->st_mode))
		ft_printf("   %*d, %*d", clength->major + 1,
			(file->infos->st_rdev) >> 24, clength->minor_or_size,
			(file->infos->st_rdev) & 16777215);
	else
		ft_printf("  %*d", clength->major != 0 ? ((clength->minor_or_size * 2)
		+ clength->major + 1) : clength->minor_or_size, file->infos->st_size);
	print_filedate(file);
	ft_printf(" %s", file->name);
	print_linked_file(file, dirname);
	ft_printf("\n");
	return (1);
}

int		read_file(t_file *file, t_command *command, char *dirname,
	t_column *clength)
{
	if (clength == NULL)
		return (0);
	if (!has_option(command->options, 'l'))
		ft_printf("%s\n", file->name);
	else
		if (!read_long_format(file, command, dirname, clength))
			return (0);
	return (1);
}
