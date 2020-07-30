#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

void 		errno_exit(void)
{
	perror(strerror(errno));
	exit(0);
}

void 		print_all_things(const t_file *file, const t_flags *flags, const t_conf *conf)
{
	//int 	num_dirs; //for what?
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags, conf);
	while (counter)
	{
		if (!ft_strequ(counter->name, ".") && !ft_strequ(counter->name, "..") && counter->is_directory)
		{
			printf("%s\n", counter->full_path);///////плюс двоеточие
			print_all_things(counter, flags, conf);
		}

		counter = counter->next;
	}
}