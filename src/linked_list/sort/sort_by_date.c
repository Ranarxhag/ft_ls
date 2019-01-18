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
		tmp = files;
		while (tmp->next)
		{
			if (tmp->date - tmp->next->date < 0)
			{
				swap_files(tmp, tmp->next);
				ordered = 0;
			}
			tmp = tmp->next;
		}
	}
}