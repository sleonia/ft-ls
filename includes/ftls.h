#ifndef FTLS_H
# define FTLS_H

# include "libft.h"
# include <sys/types.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>

# define R big_r_lol_norminette_doesnt_like_it;/////deal with this shit

typedef	struct			s_flags
{
	bool				l;
	bool				big_r_lol_norminette_doesnt_like_it;
	bool				a;
	bool				r;
	bool				t;
	int					error;////its an error or a folder with no flags

}						t_flags;

typedef struct			s_folder
{
	char				*folder_name;
	DIR					*fd;
	/////other parameters
	struct s_folders	*folders_inside;
	struct s_folders	*next;
	/////maybe this should have 2
	/////connections or even be a tree for speed purposes
	/////but for now - whatever
}						t_folder;

/*
 * read
 */

t_flags					*read_flags(char *arg);

t_folder				*read_folders(t_flags *flags, int ac, char **av);

/*
 * validate
 */

int						validate_flags(char *arg);

/*
 * deal with flags
 */

/*
 * print
 */
int						print_things(t_flags *flags, t_folder *folders);

/*
 * utils
 */

#endif
