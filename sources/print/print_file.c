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
	/////conf2 = хуй пойми что исправить
	t_conf  *conf2 = file->origin->conf;
	if (flags->i)
		ft_printf("%*llu ", conf2->inode_nbr_len + 1, file->stat.st_ino);
	if (flags->l || flags->g)
		print_all_info(file, conf2, flags);
	else
	{
		print_with_color((const struct stat*)&file->stat, (const char*)file->name);
		if (flags->one)
			ft_printf("\n");
		else
		{
			if (is_next && flags->m)
				ft_printf(", ");
			else if (is_next)
				ft_printf(" ");
		}
	}
}
