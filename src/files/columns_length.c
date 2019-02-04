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

static int			set_min_nlink(t_file *files, t_command *command)
{
	t_file	*tmp;
	int		max;
	int		result;

	max = 0;
	tmp = files;
	result = 0;
	while (tmp)
	{
		if (!has_option(command->options, 'a') && tmp->name[0] == '.')
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

static int			set_min_gname(t_file *files, t_command *command)
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
		if (!has_option(command->options, 'a') && tmp->name[0] == '.')
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

static int			set_min_uname(t_file *files, t_command *command)
{
	t_file 	*tmp;
	int		max;
	int		result;
	struct passwd *pwd;

	max = 0;
	tmp = files;
	pwd = NULL;
	result = 0;
	while (tmp)
	{
		if (!has_option(command->options, 'a') && tmp->name[0] == '.')
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

t_column			*set_columns_length(t_file *files, t_command *command)
{
	t_column *clength;

	if (!(clength = malloc(sizeof(*clength))))
		return (NULL);
	clength->n_link = set_min_nlink(files, command);
	clength->uname = set_min_uname(files, command);
	clength->gname = set_min_gname(files, command);
	clength->minor_or_size = set_min_size_or_minor(files, command);
	//clength->major = set_major(files, command);
	return (clength);
}
