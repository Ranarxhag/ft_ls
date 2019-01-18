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

static void	swap_file1(t_file *file1, t_file *file2)
{
	file1->name = file2->name;
	file1->date = file2->date;
}

static void	swap_file2(t_file *file2, t_file *file1)
{
	file2->name = file1->name;
	file2->date = file1->date;
}

void		swap_files(t_file *file1, t_file *file2)
{
	t_file *tmp;

	tmp = file1;
	swap_file1(file1, file2);
	swap_file2(file2, tmp);
}
