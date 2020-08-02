#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool should_print(const t_flags *flags, t_file *file)
{
	if (file)
	{
		if (!file->is_error)
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
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags, conf);
	while (counter)
	{
		if (should_print(flags, counter) && counter->type == Directory)
		{
			ft_printf("%s:\n", counter->full_path);
			print_all_things(counter, flags, conf);
		}

		counter = counter->next;
	}
}