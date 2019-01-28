/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:13:43 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/21 19:13:44 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_files(t_file *files)
{
	t_file *tmp;
	int length;

	length = 0;
	tmp = files;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}
