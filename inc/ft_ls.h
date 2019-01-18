/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:51:11 by bjovanov          #+#    #+#             */
/*   Updated: 2019/01/11 07:51:12 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>
#include <time.h>
#include "../libft/includes/libft.h"

/***
Supprimer plus tard
*****/
#include <stdio.h>

#define ALLOWED_OPTIONS "Ralrt"

typedef struct 		s_file
{
	char			*name;
	time_t			date;
	struct s_file	*next;
}					t_file;

typedef struct 		s_command
{
	char	*options;
	t_file	*paths;
}					t_command;

t_command			*set_command(int argc, char **argv);
void				delete_command(t_command *command);
char				*set_options(int argc, char **argv, int *i);
t_file				*set_paths(char *options, int argc, char **argv, int i);
t_file				*new_file(char *name, time_t date);
void				add_file_last(t_file **list, t_file *file);
void				add_file_first(t_file **list, t_file *file);

void				no_such_file_or_directory(char *filename);
void				illegal_option(char c);

int					has_option(char *options, char c);

void				set_file_order(t_file *files, char *options);
void				sort_by_date(t_file *files, char *options);

void				swap_files(t_file *file1, t_file *file2);
#endif
