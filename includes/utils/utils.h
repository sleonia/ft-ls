#ifndef UTILS_H
# define UTILS_H

#include "types.h"
#include "ft_printf.h"
#include <pwd.h>
#include <grp.h>

/*!
** \file
** \brief Some utils:
**	- create structs
**	- build full path to a file
**	- calculate length of nbr
**	- take config for output on file
*/

t_flags		*init_flags(void);
t_file 		*init_file(void);
t_file		*new_file(t_file *prev);
t_conf		*new_conf(void);

char 		*build_path(t_file *file);
char 		*build_path_for_arg(const char *name);

int			nbrlen(long long nbr);
void		take_config(const char *name, const struct stat *stat, t_conf *conf);

int 		free_all(t_file *files, t_conf *conf, t_flags *flags);

int			get_type(mode_t mode);

char		get_attributes(const char *name);

#endif
