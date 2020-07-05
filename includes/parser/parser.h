#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include "libft.h"
# include <sys/types.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>

bool					parser(const char **, t_folder *, t_flags *);
t_flags                 *read_flags(const char **);
t_folder				*read_folders(const char **);
int                     validate_flags(t_flags *, const char *);

#endif
