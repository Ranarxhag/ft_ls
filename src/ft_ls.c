/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 08:10:12 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/11 08:10:13 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_config *config;

	if (!(config = set_config(argc, argv)))
		exit(EXIT_FAILURE);
} 
