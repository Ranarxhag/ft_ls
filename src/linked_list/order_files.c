/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:08:27 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/17 20:08:29 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_file_order(t_file *files, char *options)
{
	if (files == NULL || count_files(files) == 1)
		return ;
	sort_by_ascii(files);
	if (has_option(options, 't'))
		sort_by_date(files, options);

	if (has_option(options, 'r'))
		sort_reverse(&files);
}

