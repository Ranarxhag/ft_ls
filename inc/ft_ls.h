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
#include "../libft/includes/libft.h"

#define ALLOWED_OPTIONS "lRart"

typedef struct 		s_lsconfig
{
	char	*options;
	char	**paths;
}					t_lsconfig;

typedef struct 		s_file
{
	char			*name;
	time_t			last_modification;
	struct s_file	*next;
}					t_file;

typedef struct 		s_dir
{
	char			*path;
	t_file			*files;
	struct s_dir	*next;
}					t_dir;

t_lsconfig	*set_config(int argc, char **argv);

#endif
