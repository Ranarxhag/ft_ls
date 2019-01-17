/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:12:48 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/17 16:12:49 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_file_last(t_file **list, t_file *file)
{
	if (list == NULL || file == NULL)
		return ;
	if (*list == NULL)
	{
		*list = file;
		return ;
	}
	if ((*list)->next)
		add_file_last(&((*list)->next), file);
	if (!(*list)->next)
		(*list)->next = file;
}

void	add_file_first(t_file **list, t_file *file)
{
	if (list == NULL || file == NULL)
		return ;
	file->next = *list;
	*list = file;
}