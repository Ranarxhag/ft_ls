/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:08:56 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/06 19:08:56 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_linked_file(t_file *file, char *dirname)
{
	char	buf[1024];
	ssize_t	len;
	char	*tmp;
	char	*tmp2;
	if (!S_ISLNK(file->infos->st_mode))
		return ;
	if (!(tmp = ft_strjoin(dirname, "/")))
		return ;
	if (!(tmp2 = ft_strjoin(tmp, file->name)))
	{
		ft_strdel(&(tmp));
		return ;
	}
	if ((len = readlink(tmp2, buf, 1023)) == -1)
	{
		perror("ft_ls: ");
		ft_strdel(&(tmp));
		ft_strdel(&(tmp2));
		return ;
	}
	buf[len] = '\0';
	ft_printf(" -> %s", buf);
	ft_strdel(&(tmp));
	ft_strdel(&(tmp2));
}

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

void	print_filedate(t_file *file)
{
	char	date[13];
	time_t	curtime;
	char	*mtime;

	date[12] = '\0';
	mtime = ctime(&(file->infos->st_mtime));
	mtime[ft_strlen(mtime) - 1] = '\0';
	time(&curtime);
	if (curtime + 15552000 < file->infos->st_mtime)
	{

		ft_strncpy(date, mtime + 4, 6);
		ft_memset((void*)date + 6, ' ', 6);
		ft_strncpy(date + 8, mtime + 20, 4);
	}
	else
		ft_strncpy(date, mtime + 4, 12);
	ft_printf(" %s", date);
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
