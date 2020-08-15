#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief Manage of print
*/

static void		print_one(const t_file *files, const t_flags *flags) {
	if (files) {
		if (files->type == Directory)
			print_directory(files->files_inside, flags);
		else {
			print_file(files, flags, files->next);
			ft_printf("\n");
		}
		print_one(files->next, flags);
	}
}

static void		print_many(const t_file *files, const t_flags *flags)
{
	t_file	*counter;

	counter = (t_file *)files;
	while (counter) {
		if (counter->type != Directory && !counter->is_error)
			print_file(counter, flags, true);
		counter = counter->next;
	}
	if (files->next || files->type == Regular)
		ft_printf("\n");
	counter = (t_file *)files;
	while (counter) {
		if (counter->files_inside && !counter->is_error) {
			ft_printf("%s:\n", counter->name);
			print_directory(counter->files_inside, flags);
			if (counter->next)
				ft_printf("\n");
		}
		counter = counter->next;
	}
}

static void		print_things(const t_flags *flags, const t_file *files) {
	if (files->next)
		print_many(files, flags);
	else {
		if (!files->is_error)
			print_one(files, flags);
	}
}

void			print(const t_flags *flags, const t_file *files) {
	t_file		*tmp;

	tmp = (t_file *)files;
	if (flags->big_r) {
		while (tmp) {
			if (tmp->type == Directory && !tmp->is_error) {
				if (tmp->next)
					ft_printf("%s:\n", tmp->name);
				print_all_things(tmp, flags);
			} else if (tmp->type != Directory && !tmp->is_error)
				print_file(tmp, flags, tmp->next);
			tmp = tmp->next;
		}
	} else
		print_things(flags, files);
}
