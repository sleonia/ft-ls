#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool should_print(t_flags *flags, t_file *file)
{
	if (file)
	{
		if (file->name)
		{
			if (file->name[0] == '.')
			{
				if (!flags->a && !file->no_ignore)
					return (false);
			}
			return (true);
		}
	}
	return (false);
}

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
	if (file->is_directory)
		print_directory(counter, flags, conf);
	else
		print_file(file, flags, false, conf);
	while (counter)
	{
		if (should_print(flags, counter) && counter->is_directory)
		{
			printf("%s:\n", counter->full_path);///////плюс двоеточие
			print_all_things(counter, flags, conf);
		}

		counter = counter->next;
	}
}