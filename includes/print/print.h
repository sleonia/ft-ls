#ifndef PRINT_H
#define PRINT_H

#include "ft_printf.h"
#include "types.h"
#include <errno.h>

/*!
** \file
** \brief Functions for print output
*/

/*!
**	\brief Matrix filed for print with color
*/

typedef struct			s_matrix {
	char				*name;
	mode_t				st_mode;
	unsigned			ino;
	unsigned 			ino_nbr_len;
}						t_matrix;

/*!
**	\brief Stuct for save data for print with column
*/

typedef struct			s_cols {
	struct ttysize		ts;
	int					cols;
	int					max_file_len;
	int					files_actual;
	int					files_count_total;
	int					term_width;
	int					files_per_col;
	int					files_done;
	int					row;
}						t_cols;

/*
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

void					print_illegal_opt(const char symb);

void					print_directory(const t_file *files, const t_flags *flags);

void					print_all_things(const t_file *files, const t_flags *flags);

void					print_all_info(const t_file *files, const t_flags *flags);

void					print_file(const t_file *files, const t_flags *flags, bool is_next);

void					print_with_color(const mode_t st_mode, const char *name, int width);

void					print_column(t_file *files, const t_flags *flags);

void					print(const t_flags *flags, const t_file *files);

void					print_link_value(const char *full_path);

void					print_size(const struct stat *stat_, unsigned size);


#endif
