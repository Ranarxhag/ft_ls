/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:55:07 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/21 18:55:09 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*get_file_at_position(t_file *files, int position)
{
	int i;
	t_file *file;

	i = 0;
	file = files;
	while (i < position)
	{
		file = file->next;
		i++;
	}
	return (file);
}

t_file	*get_last_file(t_file *files)
{
	t_file *file;

	file = files;
	while (file->next)
		file = file->next;
	return (file);
}
