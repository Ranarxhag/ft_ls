/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:49:55 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/17 15:49:56 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(char *name, time_t date)
{
	t_file *file;

	if(!(file = malloc(sizeof(*file))))
		return (NULL);
	if (!(file->name = ft_strdup((const char *)name)))
	{
		ft_memdel((void**)&(file));
		return (NULL);
	}
	file->date = date;
	file->next = NULL;
	return (file);
}
