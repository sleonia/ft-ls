#include "output/output.h"
#include "types.h"

/*!
** \file
** \brief
*/

void			print(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file* tmp = (t_file *)files;

	if (flags->big_r)
		print_all_things((const t_file *)files, flags, conf);
	else
		print_directory(files->files_inside, (const t_flags*)flags, conf);
	print_column(NULL, NULL, NULL, conf);
}
