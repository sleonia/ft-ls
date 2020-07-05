#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <stdbool.h>
# include <string.h>

/*!
* \file
* \brief Functions for parse input by flags and folders
*/

bool		parser(const char **, t_folder *, t_flags *);
bool		read_flags(t_flags *, const char **);
bool		read_folders(t_folder *,const char **);
int			validate_flags(t_flags *, const char *);

#endif
