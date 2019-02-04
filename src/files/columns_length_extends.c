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
	if (max > 0)
	{

	}
	printf("%d\n", file->infos->st_dev);
	return (max);
}

int		set_min_size_or_minor(t_file *files, t_command *command)
{
	int		max;
	t_file	*tmp;
	
	max = 0;
	tmp = files;
	while (tmp)
	{
		if (!has_option(command->options, 'a') && tmp->name[0] == '.')
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
