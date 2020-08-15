#ifndef PARSER_H
#define PARSER_H

#include "types.h"
#include "libft/libft.h"
#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*!
** \file
** \brief Functions for parse input by flags and folders
*/

bool	parser(const char **av, t_file *files, t_flags *flags, int ac);

int		read_flags(t_flags *flags, const char **av, int ac);
int		validate_flags(t_flags *flags, const char *arg);

void	read_files(int index, t_file *files, const char **args, t_flags *flags);
void	fill_file(const char *name, t_file *file, t_flags *flags);

#endif
