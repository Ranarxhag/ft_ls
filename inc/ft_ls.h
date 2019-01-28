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
#include <sys/types.h>
#include <dirent.h>
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
	struct stat		*infos;
	struct s_file	*next;
}					t_file;

typedef struct 		s_wait
{
	char			*path;
	struct s_wait	*next;
}					t_waiting;

typedef struct 		s_command
{
	char	*options;
	t_file	*paths;
}					t_command;

t_command			*set_command(int argc, char **argv);
void				delete_command(t_command *command);
char				*set_options(int argc, char **argv, int *i);
t_file				*set_paths(char *options, int argc, char **argv, int i);
t_file				*new_file(char *name, struct stat *fileinfo);
void				add_file_last(t_file **list, t_file *file);
void				add_file_first(t_file **list, t_file *file);
void				add_waiting_last(t_waiting **list, t_waiting *waiting);
void				add_waiting_first(t_waiting **list, t_waiting *waiting);

void				no_such_file_or_directory(char *filename);
void				illegal_option(char c);
int					error_opendir(char *dirname);

int					has_option(char *options, char c);

void				set_file_order(t_file *files, char *options);
void				sort_by_date(t_file *files, char *options);
void				sort_reverse(t_file **files);
void				sort_by_ascii(t_file *files);

void				swap_files(t_file *file1, t_file *file2);
t_file				*get_last_file(t_file *files);
t_file				*get_file_at_position(t_file *files, int position);
int					count_files(t_file *files);

int					read_directory(char *dirname, t_command *command,
					int newline, int nb_paths);
int					read_file(t_file *file, t_command *command);
t_file				*store_files(char *dirname, DIR *dirp, t_command *command);
int					read_files(t_file *files, char *dirname,
					t_waiting **waiting, t_command *command);
t_waiting			*delete_waiting(t_waiting **waiting);
t_waiting			*new_waiting(char *pathname);

t_file				*delete_files(t_file **files);
#endif
