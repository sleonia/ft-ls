#ifndef UTILS_H
# define UTILS_H

/*!
* \file
* \brief Some utils
	- create structs
*/

#include "types.h"

t_flags		*init_flags(void);
t_file 		*init_file(void);
void		new_file(t_file *prev);

#endif
