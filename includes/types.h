#ifndef TYPES_H
# define TYPES_H

/*!
* \file
* \brief Types of structs in program
*/

#include <dirent.h>
#include <stdbool.h>

/*!
file
    - file name
    - file descriptor
    - file type flag
    - folder inside is not NULL if is_folder == TRUE
    - pointer to next element
    - pointer to prev element
    - creation time
*/

typedef struct			s_file
{
	char				*name;
	DIR					*fd;
	bool				is_folder;
	struct s_file		*files_inside;
	struct s_file		*next;
	struct s_file		*prev;
	struct t_time		*created;////only used with -t flag, no need to do it otherwise
}						t_file;

/*!
* Parsing ls arguments - directories and flags
* struct for program flags contain:
*   - R
*   - r
*   - l
*   - a
*   - t
*   - 1
*/

typedef	struct			s_flags
{
	bool				big_r;
	bool				little_r;
	bool				l;
	bool				a;
	bool				t;
	bool				one;
	bool				no_flags;////added temporarily, should delete if its useless
}						t_flags;
#endif