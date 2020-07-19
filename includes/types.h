#ifndef TYPES_H
# define TYPES_H

/*!
** \file
** \brief Types of structs in program
*/

#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <time.h>

/*!
** file:
**     - file name
**     - file descriptor
**     - file type flag
**     - folder inside is not NULL if is_folder == TRUE
**     - pointer to next element
**     - pointer to prev element
**     - creation time
*/

typedef struct			s_file////////maybe i should make it more readable, this shit has become too big to debug. lol kek some of my old projects are fucking crazy
{
	char				*name;
	char 				*full_path;
	DIR					*fd;
	bool				is_directory;
	struct s_file		*files_inside;
	struct s_file		*origin;////the directory containing this file, may be useful, will delete if not
	struct s_file		*next;
	time_t				time;
	struct stat			stat;
	struct dirent		*dirent;
	bool				no_ignore;
}						t_file;

/*!
** Parsing ls arguments - directories and flags
** struct for program flags contain:
**   - R
**   - r
**   - l
**   - a
**   - t
**   - g
**   - m
**   - 1
**   - f
**   - i
*/

typedef	struct			s_flags
{
	bool				big_r;
	bool				little_r;
	bool				l;
	bool				a;
	bool				t;
	bool				g;
	bool				m;
	bool				one;
	bool				f;
	bool				i;
	bool				no_flags;
}						t_flags;

/*!
**	Struct for correct output of ls
**	  filed:
**		- total size
**		- count of files
**		- rights len
*/

typedef	struct			s_conf
{
	unsigned			total;
	unsigned			count;
	unsigned			rights_len;
	unsigned			links_len;
	unsigned			creator_len;
	unsigned			group_len;
	unsigned			size_len;
	unsigned			name_len;
	unsigned			inode_nbr_len;
}						t_conf;

#endif
