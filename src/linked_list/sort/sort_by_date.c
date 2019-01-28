/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:19:09 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/18 07:19:09 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_date(t_file *files, char *options)
{
	int		ordered;
	t_file	*tmp;

	ordered = 0;
	tmp = files;
	if (options) {

	}
	while (!ordered)
	{
		ordered = 1;
		files = tmp;
		while (files->next)
		{
			//printf("%s %ld | %s %ld\n", files->name, files->infos->st_mtime, files->next->name, files->next->infos->st_mtime);
			if (files->infos->st_mtime < files->next->infos->st_mtime)
			{
				swap_files(files, files->next);
				ordered = 0;
			}
			files = files->next;
		}
	}
	files = tmp;
}