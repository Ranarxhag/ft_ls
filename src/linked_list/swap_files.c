/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:36:31 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/18 14:36:32 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap_files(t_file *file1, t_file *file2)
{
	t_file tmp;

	tmp.name = file1->name;
	tmp.infos = file1->infos;
	file1->name = file2->name;
	file1->infos = file2->infos;
	file2->name = tmp.name;
	file2->infos = tmp.infos;
}
