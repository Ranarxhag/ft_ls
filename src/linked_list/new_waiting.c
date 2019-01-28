/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_waiting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:38:07 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/23 17:38:08 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_waiting	*new_waiting(char *pathname)
{
	t_waiting *dir;

	if (pathname == NULL)
		return (NULL);
	if(!(dir = malloc(sizeof(*dir))))
		return (NULL);
	if (!(dir->path = ft_strdup((const char *)pathname)))
	{
		ft_memdel((void**)&(dir));
		return (NULL);
	}
	dir->next = NULL;
	return (dir);
}
