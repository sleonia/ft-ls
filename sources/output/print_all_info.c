#include "output/output.h"
#include "types.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

/*!
*	Example of ctime(&file->stat.st_mtime) -> Tue Jul 14 02:36:07 2020
*/

static void		print_time(const time_t *time)
{
	char	buffer[13];
	char	*line_time;
	int		i;

	line_time = ctime(time) + 4;
	ft_memset(buffer, ' ', sizeof(buffer));
	buffer[0] = line_time[4];
	buffer[1] = line_time[5];
	buffer[3] = line_time[0];
	buffer[4] = line_time[1];
	buffer[5] = line_time[2];
	buffer[12] = 0;
	i = 6;
	while (++i < 12)
		buffer[i] = line_time[i];
	printf("%s ", buffer);
}

static void		print_rights(const struct stat *stat)
{
	printf((S_ISDIR(stat->st_mode)) ? "d" : "-");
    printf((stat->st_mode & S_IRUSR) ? "r" : "-");
    printf((stat->st_mode & S_IWUSR) ? "w" : "-");
    printf((stat->st_mode & S_IXUSR) ? "x" : "-");
    printf((stat->st_mode & S_IRGRP) ? "r" : "-");
    printf((stat->st_mode & S_IWGRP) ? "w" : "-");
    printf((stat->st_mode & S_IXGRP) ? "x" : "-");
    printf((stat->st_mode & S_IROTH) ? "r" : "-");
    printf((stat->st_mode & S_IWOTH) ? "w" : "-");
    printf((stat->st_mode & S_IXOTH) ? "x " : "- ");
}

/*!
*	What is info about file/link/folder?
*		-rwxr-xr-x   1 a18573961  staff  38528 14 Jul 21:16 ft_ls
*	Transcript:
*		- rights
*		- count of link
*		- name of creator
*		- name of group
*		- size of bytes
*		- time
*		- file name
*/

void			print_all_info(const struct stat *stat, const char *name)
{
	print_rights(stat);
	printf("%d ", stat->st_nlink);
	printf("%s ", (getpwuid(stat->st_uid))->pw_name);
	printf("%s ", getgrgid(stat->st_gid)->gr_name);
	printf("%lld ", stat->st_size);
	print_time(&stat->st_mtime);
	printf("%s\n", name);
}