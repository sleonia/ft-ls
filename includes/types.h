/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:21:50 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 19:49:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/*
** \file
** \brief Types of structs in program
*/

# include <dirent.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/ioctl.h>

/*
**	Types of files in unix
*/

typedef enum			e_types
{
	Regular,
	Directory,
	Character_device,
	Block_device,
	Socket,
	Link,
	Unknown
}						t_types;

/*
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

typedef	struct			s_conf
{
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

/*
** file:
**     - file name
**     - full path
**     - files in dir
**     - ?
**     - pointer to next
**     - readdir info
**     - type of file
**     - is ignor
**     - is error
**     - is done
*/

typedef	struct			s_file
{
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

/*
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
	bool				no_flags;
}						t_flags;

#endif
