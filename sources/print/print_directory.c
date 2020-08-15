#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief Print directory and its contains
*/

static bool		should_print(t_file *file, const t_flags *flags) {
	if (file->name[0] == '.' && !file->no_ignore)
		return (flags->a ? true : false);
	return (true);
}

void			print_directory(const t_file *file, const t_flags *flags) {
	t_file	*tmp;

	tmp = (t_file *)file;
	if (flags->l || flags->g)
		ft_printf("total: %d\n", file->origin->conf->total);
	if (flags->m || flags->l || flags->g) {
		while (tmp) {
			if (should_print(tmp, flags)) {
				if (tmp->name)
					print_file((const t_file*)tmp, flags, tmp->next);
			}
			tmp = tmp->next;
		}
		if (flags->m)
			ft_printf("\n");
	} else if (file)
		print_column(file->origin, flags);
}
