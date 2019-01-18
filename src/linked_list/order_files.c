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
	if (has_option(options, 't'))
		sort_by_date(files, options);
	else
		printf("NTM\n");
}

