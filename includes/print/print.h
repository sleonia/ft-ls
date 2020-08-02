#ifndef OUTPUT_H
# define OUTPUT_H

#include "ft_printf.h"
#include "types.h"
#include <errno.h>

/*!
** \file
** \brief Functions for print output
*/

void    	    print_illegal_opt(const char);
void 			print_directory(const t_file *file, const t_flags *flags, const t_conf *conf);
void 			print_all_things(const t_file *file, const t_flags *flags, const t_conf *conf);
void			print_all_info(const struct stat *stat_, const t_conf *conf, bool is_flag_g, const char *name);
void 			print_file(const t_file *file, const t_flags *flags, bool is_next, const t_conf *conf);
void			print_with_color(const struct stat *stat_, const char *name);
void			print_column(const t_file *file, const t_flags *flags, bool is_next, const t_conf *conf);
void			print(const t_flags *flags, const t_file *files, const t_conf *conf);

void			print_link_value(const char *name);

void			print_size(const struct stat *stat_, unsigned size);

/*test me*/
void 	print_directory_v2(t_file *file, t_flags *flags, t_conf *conf); ///////////////?

/*!
**	Colors
*/

#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_BOLD_GREEN "\x1b[32;1m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_BOLD_CYAN  "\x1b[96;1m"
#define ANSI_COLOR_RESET      "\x1b[0m"

#endif
