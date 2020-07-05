#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <stdbool.h>
# include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*!
* \file
* \brief Functions for parse input by flags and folders
*/

bool		parser(const char **, t_file *, t_flags *, int);
int			read_flags(t_flags *, const char **, int);
bool		read_files(int, t_file *,const char **, int);
int			validate_flags(t_flags *, const char *);

#endif
