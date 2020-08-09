/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:27:40 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 18:00:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include "ft_printf.h"
# include "print/print.h"
# include <pwd.h>
# include <grp.h>

/*
** \file
** \brief Some utils for project
** \details utils:
**	- create structs
**	- build full path to a file
**	- calculate length of nbr
**	- take config for output on file
*/

t_flags		*init_flags(void);
t_file		*init_file(void);
t_file		*new_file(t_file *prev);
t_conf		*new_conf(void);

char		*build_path(t_file *file);
char		*build_path_for_arg(const char *name);

int			nbrlen(long long nbr);
void		take_config(const char *name, const struct stat *stat,
						const t_flags *flags, t_conf *conf);

int			free_all(t_file *files, t_flags *flags);

int			get_type(mode_t mode);

char		get_attributes(const char *name);

void		del_last(t_file *prev, t_file *curr);

void		free_matrix(t_cols *cols, t_matrix **matrix);

#endif
