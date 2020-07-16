#include "output/output.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool should_print(const char *name, const bool flag_a)
{
	if (ft_strequ(name, ".") || ft_strequ(name, ".."))
		return (flag_a ? true : false);
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
		if (should_print(tmp->name, flags->a))
		{
			if (tmp->name)
			{
				is_last = tmp->next && tmp->next->next ? true : false;
				print_file((const t_file*)tmp, flags, is_last, conf);
			}
		}
		tmp = tmp->next;
	}
	printf("\n");
}
