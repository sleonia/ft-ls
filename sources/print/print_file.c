#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>

/*!
** \file
** \brief
*/

void 		print_file(const t_file *file, const t_flags *flags,
						bool is_next, const t_conf *conf)
{
	if (flags->i)
		printf("%*llu ", conf->inode_nbr_len + 1, file->stat.st_ino);////ft_printf!
	if (flags->l || flags->g)
		print_all_info(&file->stat, conf, flags->g, (const char *)file->name);
	else
	{
		print_with_color((const struct stat*)&file->stat, (const char*)file->name);
		if (flags->one)
			printf("\n");
		else
		{
			if (is_next && flags->m)
				printf(", ");
			else if (is_next)
				printf(" ");
		}
	}
}
