#ifndef OUTPUT_H
# define OUTPUT_H

#include "libft.h"
#include "types.h"
#include <errno.h>

/*!
* \file
* \brief Functions for print output
*/

void        print_illegal_opt(const char);
void 		errno_exit(void);
void 		print_files_test(t_file *file, t_flags *flags);

#endif