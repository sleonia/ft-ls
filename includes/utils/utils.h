#ifndef UTILS_H
# define UTILS_H

/*!
* \file
* \brief Some utils
	- create structs
	- build full path to a file
*/

#include "types.h"

t_flags		*init_flags(void);
t_file 		*init_file(void);
t_file		*new_file(t_file *prev);
char 		*build_path(t_file *file);

#endif
