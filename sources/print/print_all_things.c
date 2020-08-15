#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool	should_print(const t_flags *flags, t_file *file) {
	if (file && !file->is_error && file->name) {
		if (file->name[0] == '.') {
			if (!flags->a && !file->no_ignore)
				return (false);
		}
		return (true);
	}
	return (false);
}

void		print_all_things(const t_file *file, const t_flags *flags) {
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags);
	ft_printf("\n");
	while (counter) {
		if (should_print(flags, counter) && counter->type == Directory) {
			ft_printf("%s:\n", counter->full_path);
			print_all_things(counter, flags);
		}
		counter = counter->next;
	}
}
