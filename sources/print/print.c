#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

static void 	print_one(t_file *files, const t_flags *flags, const t_conf *conf)
{
	if (files)
	{
		if (S_ISDIR(files->stat.st_mode))
			print_directory(files->files_inside, flags, conf);
		else
			print_file(files, flags, true, conf);
		if (files->next)
			ft_printf("\n");
		print_one(files->next, flags, conf);
	}
}

static void 	print_many(const t_file *files, const t_flags *flags, const t_conf *conf)
{
	t_file *counter;

	counter = (t_file *)files;
	while (counter)
	{
		if (!(S_ISDIR(counter->stat.st_mode)) && !counter->is_error)
			print_file(counter, flags, true, conf);
		counter = counter->next;
	}
	ft_printf("\n");
	counter = (t_file *)files;
	while (counter)
	{
		if (counter->files_inside && !counter->is_error)
		{
			ft_printf("%s:\n", counter->name);
			print_directory(counter->files_inside, flags, conf);
		}
		counter = counter->next;
	}
}

static void 	print_things(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file *counter;

	counter = (t_file *)files;
	if (files->next)
		print_many(files, flags, conf);
	else
	{
		if (!files->is_error)
			print_one((t_file *)files, flags, conf);
	}
}

void			print(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file		*tmp;
	bool		many_args;

	tmp = (t_file *)files;
	many_args = tmp->next ? true : false;
	if (flags->big_r)
	{
		while (tmp)
		{
			if (tmp->type == Directory && !tmp->is_error)
			{
				if (many_args)
					ft_printf("%s:\n", tmp->name);
				print_all_things(tmp, flags, conf);
			}
			else if (tmp->type != Directory && !tmp->is_error)
			{
				print_file(tmp, flags, tmp->next ? true : false, conf);
				ft_printf("\n");
			}
			tmp = tmp->next;
		}
	}
	else
		print_things(flags, files, conf);
	//print_column(files, flags, conf);
}
