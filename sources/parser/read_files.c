#include "parser/parser.h"
#include "utils/utils.h"
#include "print/print.h"

/*!
** \file
** \brief
*/

void			del_last(t_file *prev, t_file *curr)
{
	prev->next = NULL;
	ft_memdel((void **)&curr);
}

void			read_files(int index, t_file *files, const char **args,
		t_flags *flags)
{
	t_file	*tmp;
	t_file	*prev;

	tmp = files;
	if (!args[index])
	{
		files->no_ignore = true;
		fill_file("./", files, flags);
	}
	else
	{
		if (flags->no_flags)
			index = 0;
		while (args[++index])
		{
			tmp->no_ignore = true;
			tmp->full_path = build_path_for_arg(args[index]);
			fill_file(args[index], tmp, flags);
			prev = tmp;
			tmp = new_file(tmp);
		}
		if (!tmp->name)
			del_last(prev, tmp);
	}
}
