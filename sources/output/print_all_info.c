#include "output/output.h"
#include "types.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

/*!
**	What is info about file/link/folder?
**		-rwxr-xr-x   1 a18573961  staff  38528 14 Jul 21:16 ft_ls
**	Transcript:
**		- rights
**		- count of link
**		- name of creator
**		- name of group
**		- size of bytes
**		- time
**		- file name
*/

/*!
**	Example of ctime(time) -> Tue Jul 14 02:36:07 2020
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

static void		print_rights(const mode_t mode)
{
	char		rights[11];

	rights[0] = (S_ISDIR(mode)) ? 'd' : '-';
	rights[1] = (mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (mode & S_IROTH) ? 'r' : '-';
	rights[8] = (mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (mode & S_IXOTH) ? 'x' : '-';
	rights[10] = 0;
	printf("%s ", rights);
}

void			print_all_info(const struct stat *stat_, const t_conf *conf,
					const bool is_flag_g, const char *name)
{
	print_rights(stat_->st_mode);
	printf("%*d ", conf->links_len + 1, stat_->st_nlink);
	if (!is_flag_g)
		printf("%-*s ", conf->creator_len + 1, (getpwuid(stat_->st_uid))->pw_name);
	printf("%-*s ", conf->group_len, getgrgid(stat_->st_gid)->gr_name);
	printf("%*lld ", conf->size_len + 1, stat_->st_size);
	print_time(&stat_->st_mtime);
	print_with_color(stat_, name);
	printf("\n");
}