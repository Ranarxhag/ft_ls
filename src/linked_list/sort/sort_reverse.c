/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:23:03 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/21 16:23:03 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_reverse(t_file **files)
{
	t_file 	*file1;
	t_file 	*file2;
	int 	countfiles;
	int		i;

	i = 0;
	countfiles = count_files(*files);
	file1 = NULL;
	file2 = NULL;
	while (i < countfiles / 2)
	{
		file1 = get_file_at_position(*files, i);
		file2 = get_file_at_position(*files, countfiles - i - 1);
		swap_files(file1, file2);
		i++;
	}
}
