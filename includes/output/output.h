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
void 		print_directory(t_file *file, const t_flags *flags);
void 		print_file(const t_file *file, const t_flags *flags);
void 		print_all_things(t_file *file, const t_flags *flags);

#endif