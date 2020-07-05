#ifndef UTILS_H
# define UTILS_H

/*!
* \file
* \brief Some utils
	- create structs
*/

#include "types.h"

t_flags		*init_flags(void);
t_folder	*init_folder(void);
void		new_folder(t_folder *prev);

#endif
