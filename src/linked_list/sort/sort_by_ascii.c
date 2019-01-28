/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:45:55 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/23 17:45:56 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_ascii(t_file *files)
{
	int		ordered;
	t_file	*tmp;

	ordered = 0;
	tmp = files;
	while (!ordered)
	{
		ordered = 1;
		files = tmp;
		while (files->next)
		{
			if (ft_strcmp(files->name, files->next->name) > 0)
			{
				swap_files(files, files->next);
				ordered = 0;
			}
			files = files->next;
		}
	}
	files = tmp;
}
