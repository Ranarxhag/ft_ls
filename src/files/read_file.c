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
	if (S_ISSOCK(file->infos->st_mode))
		return ('s');
	else if (S_ISLNK(file->infos->st_mode))
		return ('l');
	else if (S_ISDIR(file->infos->st_mode))
		return ('d');
	else if (S_ISCHR(file->infos->st_mode))
		return ('c');
	else if (S_ISFIFO(file->infos->st_mode))
		return ('p');
	else if (S_ISBLK(file->infos->st_mode))
		return ('b');
	return ('-');
}

char	*read_permissions(t_file *file)
{
	char *str;

	if (!(str = ft_strnew(10)))
		return (NULL);
	str[0] = set_filetype(file);
	str[1] = (file->infos->st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (file->infos->st_mode & S_IWUSR) ? 'w' : '-';
	if (file->infos->st_mode & S_ISUID)
		str[3] = (file->infos->st_mode & S_IXUSR) ? 's' : 'S';
	else
		str[3] = (file->infos->st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (file->infos->st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (file->infos->st_mode & S_IWGRP) ? 'w' : '-';
	if (file->infos->st_mode & S_ISGID)
		str[6] = (file->infos->st_mode & S_IXGRP) ? 's' : 'S';
	else
		str[6] = (file->infos->st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (file->infos->st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (file->infos->st_mode & S_IWOTH) ? 'w' : '-';
	if (file->infos->st_mode & S_ISVTX)
		str[9] = (file->infos->st_mode & S_IXOTH) ? 't' : 'T';
	else
		str[9] = (file->infos->st_mode & S_IXOTH) ? 'x' : '-';
	return (str);
}

int		read_long_format(t_file *file, t_command *command, t_column *clength)
{
	struct passwd 	*pwd;
	struct group 	*grp;
	
	if (command || clength) {

	}
	pwd = getpwuid(file->infos->st_uid);
	grp = getgrgid(file->infos->st_gid);
	ft_printf("%-10s  %*d %-*s  %-*s", read_permissions(file), 
		clength->n_link, file->infos->st_nlink, clength->uname, pwd == NULL ? 
		ft_itoa(file->infos->st_uid) : pwd->pw_name, clength->gname, grp == NULL ? ft_itoa(file->infos->st_gid) : grp->gr_name);
	ft_printf("%s %s\n", ft_strdupwc(ctime(&(file->infos->st_mtime)), '\n'), file->name);
	return (1);
}

int		read_file(t_file *file, t_command *command, t_column *clength)
{
	if (clength == NULL)
		return (0);
	if (!has_option(command->options, 'a') && file->name[0] == '.')
		return (1);
	if (!has_option(command->options, 'l'))
		ft_printf("%s\n", file->name);
	else
		if (!read_long_format(file, command, clength))
			return (0);
	return (1);
}
