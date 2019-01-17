/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:10:11 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/17 20:10:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_such_file_or_directory(char *filename)
{
	ft_putstr_fd("ft_ls: ", 2);
	if (ft_strequ("", filename))
		perror("fts_open");
	else
		perror((const char*)filename);
}

void	illegal_option(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("usage: ft_ls [-", 2);
	ft_putstr_fd(ALLOWED_OPTIONS, 2);
	ft_putendl_fd("] [file ...]", 2);
}
