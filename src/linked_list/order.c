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

void	sort_by_last_modified(t_file *files)
{

}

void	set_file_order(t_file *files, char *option)
{
	if (has_option(option, 't'))
		sort_by_last_modified(files);
}
