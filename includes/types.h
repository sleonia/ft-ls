#ifndef TYPES_H
# define TYPES_H

/*!
* \file
* \brief Structs in program
*/

#include <dirent.h>
#include <stdbool.h>

/*!
folder
    - folder name
    - file descriptor
    - folder inside ???
    - poiner to next element
*/

typedef struct			s_folder
{
	char				*folder_name;
	DIR					*fd;
	struct s_folders	*folders_inside;
	struct s_folders	*next;
	/////maybe this should have 2
	/////connections or even be a tree for speed purposes
	/////but for now - whatever
}						t_folder;

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
}						t_flags;
#endif