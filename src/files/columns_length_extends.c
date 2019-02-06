/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns_length_extends.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:31:00 by bjovanov          #+#    #+#             */
/*   Updated: 2019/02/04 18:31:01 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		set_min_size(int max, t_file *file)
{
	int result;

	result = digits_number(file->infos->st_size);
	if (result > max)
		max = result;
	return (max);
}

int		set_min_minor(int max, t_file *file)
{
	int result;
	result = digits_number((file->infos->st_rdev) & 16777215);
	if (result > max)
		max = result;
	return (max);
}

int		set_min_major(t_file *files, int only_files)
{
	int		max;
	t_file	*tmp;
	int		result;

	max = 0;
	tmp = files;
	result = 0;
	while (tmp)
	{
		if ((!tmp->infos || (only_files && S_ISDIR(tmp->infos->st_mode))) ||
			(!S_ISBLK(tmp->infos->st_mode) && !S_ISCHR(tmp->infos->st_mode)))
		{
			tmp = tmp->next;
			continue ;
		}
		result = digits_number((tmp->infos->st_rdev) >> 24);
		if (result > max)
			max = result;
		tmp = tmp->next;
	}
	return (max);
}

int		set_min_size_or_minor(t_file *files, int only_files)
{
	int		max;
	t_file	*tmp;
	
	max = 0;
	tmp = files;
	while (tmp)
	{
		if (!tmp->infos || (only_files && S_ISDIR(tmp->infos->st_mode)))
		{
			tmp = tmp->next;
			continue ;
		}
		if (S_ISBLK(tmp->infos->st_mode) || S_ISCHR(tmp->infos->st_mode))
			max = set_min_minor(max, tmp);
		else
			max = set_min_size(max, tmp);
		tmp = tmp->next;
	}
	return (max);
}
