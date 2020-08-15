#ifndef TYPES_H
#define TYPES_H

/*!
** \file
** \brief Types of structs in program
*/

# include <dirent.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/ioctl.h>

/*!
**	Types of files in unix
*/

typedef enum			e_types {
	Regular,
	Directory,
	Character_device,
	Block_device,
	Socket,
	Link,
	Unknown
}						t_types;

/*!
**	Struct for correct output of ls
**	  filed:
**		- total size
**		- count of files
**		- rights len
**		- name of creator len
**		- name of group len
**		- len of size
**		- name len
**		- file serial number (inode number)
*/

typedef	struct			s_conf {
	unsigned			total;
	unsigned			count_actual;
	unsigned			count_total;
	unsigned			rights_len;
	unsigned			links_len;
	unsigned			creator_len;
	unsigned			group_len;
	unsigned			size_len;
	unsigned			name_len;
}						t_conf;

/*!
** file:
**     - file name
**     - full path
**     - file descriptor
**     - files in dir
**     - pointer to parent
**     - pointer to next
**     - info by lstat()
**     - config for print
**     - readdir info
**     - type of file
**     - is ignor
**     - is error
**     - is done
*/

typedef	struct			s_file {
	char				*name;
	char				*full_path;
	DIR					*fd;
	struct s_file		*files_inside;
	struct s_file		*origin;
	struct s_file		*next;
	struct stat			stat;
	t_conf				*conf;
	struct dirent		*dirent;
	t_types				type;
	bool				no_ignore;
	bool				is_error;
	bool				done;
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
**   - f
*/

typedef	struct			s_flags {
	bool				big_r;
	bool				little_r;
	bool				l;
	bool				a;
	bool				t;
	bool				g;
	bool				m;
	bool				f;
	bool				no_flags;
}						t_flags;

#endif
