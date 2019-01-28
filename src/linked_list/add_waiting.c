/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_waiting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:50:49 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/23 16:50:50 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_waiting_last(t_waiting **list, t_waiting *waiting)
{
	if (list == NULL || waiting == NULL)
		return ;
	if (*list == NULL)
	{
		*list = waiting;
		return ;
	}
	if ((*list)->next)
		add_waiting_last(&((*list)->next), waiting);
	if (!(*list)->next)
		(*list)->next = waiting;
}

void	add_waiting_first(t_waiting **list, t_waiting *waiting)
{
	if (list == NULL || waiting == NULL)
		return ;
	waiting->next = *list;
	*list = waiting;
}
