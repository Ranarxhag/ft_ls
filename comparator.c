/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:28:32 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/25 16:28:34 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>


void	copy_ft_ls(char *ft_ls, char *arg, int argsleft)
{
	size_t begin;

	begin = ft_strlen(ft_ls);
	ft_strcpy(&(ft_ls[begin]), arg);
	ft_strcpy(&(ft_ls[ft_strlen(ft_ls)]), " ");
}

void	copy_ls(char *ls, char *arg, int argsleft)
{
	size_t begin;

	begin = ft_strlen(ls);
	ft_strcpy(&(ls[begin]), arg);
	ft_strcpy(&(ls[ft_strlen(ls)]), " ");
}

int		main(int argc, char **argv)
{
	char	*ft_ls;
	char	*ls;
	int		i, j;

	if (!(ft_ls = ft_strnew(1000)))
		return (0);
	if (!(ls = ft_strnew(1000)))
	{
		ft_strdel(&ft_ls);
		return (0);
	}
	i = 1;
	j = 0;
	ft_strcpy(ft_ls, "./ft_ls ");
	ft_strcpy(ls, "ls ");
	while (i < argc)
	{
		copy_ft_ls(ft_ls, argv[i], argc - i);
		copy_ls(ls, argv[i], argc - i);
		i++;
	}
	ft_strcpy(&(ft_ls[ft_strlen(ft_ls)]), ">> ft_ls_compare.txt");
	ft_strcpy(&(ls[ft_strlen(ls)]), ">> ls_compare.txt");

	system(ft_ls);
	system(ls);
	return (0);
}
