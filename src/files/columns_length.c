/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:04:00 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/04 17:04:01 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long			digits_number(long long n)
{
	long long result;

	result = 0;
	while (n > 0)
	{
		result++;
		n /= 10;
	}
	return (result);
}

static int			set_min_nlink(t_file *files, int only_files)
{
	t_file	*tmp;
	int		max;
	int		result;

	max = 0;
	tmp = files;
	result = 0;
	while (tmp)
	{
		if (!tmp->infos || (only_files && S_ISDIR(tmp->infos->st_mode)))
		{
			tmp = tmp->next;
			continue ;
		}
		result = digits_number((long long)tmp->infos->st_nlink);
		if (result > max)
			max = result;
		tmp = tmp->next;
	}
	return (max);
}

static int			set_min_gname(t_file *files, int only_files)
{
	t_file 			*tmp;
	int				max;
	int				result;
	struct group 	*grp;

	max = 0;
	tmp = files;
	grp = NULL;
	result = 0;
	while (tmp)
	{
		if (!tmp->infos || (only_files && S_ISDIR(tmp->infos->st_mode)))
		{
			tmp = tmp->next;
			continue ;
		}
		if (!(grp = getgrgid(tmp->infos->st_gid)))
			result = digits_number((long long)tmp->infos->st_gid);
		else
			result = ft_strlen(grp->gr_name);
		if (result > max)
			max = result;
		tmp = tmp->next;
	}
	return (max);
}

static int			set_min_uname(t_file *files, int only_files)
{
	t_file			*tmp;
	int				max;
	int				result;
	struct passwd	*pwd;

	max = 0;
	tmp = files;
	pwd = NULL;
	result = 0;
	while (tmp)
	{
		if (!tmp->infos || (only_files && S_ISDIR(tmp->infos->st_mode)))
		{
			tmp = tmp->next;
			continue ;
		}
		if (!(pwd = getpwuid(tmp->infos->st_uid)))
			result = digits_number((long long)tmp->infos->st_uid);
		else
			result = ft_strlen(pwd->pw_name);
		if (result > max)
			max = result;
		tmp = tmp->next;
	}
	return (max);
}

t_column			*set_columns_length(t_file *files, t_command *command,
	int only_files)
{
	t_column *clength;

	if (!(clength = malloc(sizeof(*clength))))
		return (NULL);
	if (command) {}
	clength->n_link = set_min_nlink(files, only_files);
	clength->uname = set_min_uname(files, only_files);
	clength->gname = set_min_gname(files, only_files);
	clength->minor_or_size = set_min_size_or_minor(files, only_files);
	clength->major = set_min_major(files, only_files);
	return (clength);
}
