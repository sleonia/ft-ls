#include "output/output.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool should_print(t_file *file, t_flags *flags)
{
	if ((ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))
	&& !file->no_ignore)
		return (flags->a ? true : false);
	return (true);
}

void 		print_directory(const t_file *file,
				const t_flags *flags, const t_conf *conf)
{
	t_file	*tmp;
	bool	is_last;

	tmp = (t_file *)file;
	if (flags->l || flags->g)
		printf("total: %d\n", conf->total);
	while(tmp)
	{
		if (should_print(tmp, flags))
		{
			if (tmp->name)
			{
				is_last = tmp->next && tmp->next->next ? true : false;
				print_file((const t_file*)tmp, flags, is_last, conf);
			}
		}
		tmp = tmp->next;
	}
	if (!flags->l && !flags->g)
		printf("\n");
}
