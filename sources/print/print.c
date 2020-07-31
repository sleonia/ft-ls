#include "print/print.h"
#include "types.h"

/*!
** \file
** \brief
*/

static bool		several_args(const t_file *files) //zalupa
{
	return (files->next? true : false);
}

static void 	print_one(t_file *files, const t_flags *flags, const t_conf *conf)
{
	if (files) {
		if (S_ISDIR(files->stat.st_mode))
		{
//			print_directory_v2(files->files_inside, flags, conf);
			print_directory(files->files_inside, flags, conf);
		}
		else
		{
			print_file(files, flags, true, conf);
		}
		if (files->next)
			printf("\n");
		print_one(files->next, flags, conf);
	}
}

static void 	print_many(const t_file *files, const t_flags *flags, const t_conf *conf)
{
	t_file *counter;

	counter = (t_file *)files;
	while (counter)
	{
		if (!(S_ISDIR(counter->stat.st_mode)))
			print_file(counter, flags, true, conf);
		counter = counter->next;
	}
	printf("\n");/////fix dis
	counter = (t_file *)files;
	while (counter)
	{
		if (counter->files_inside)
		{
			printf("%s:\n", counter->name);
			print_directory(counter->files_inside, flags, conf);
	//		print_directory_v2(counter->files_inside, flags, conf);
		}
		counter = counter->next;
	}
}

static void 	print_things(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file *counter;

	counter = (t_file *)files;

	if (several_args(files))
		print_many(files, flags, conf);
	else {
		print_one((t_file *)files, flags, conf);
	}
}

void			print(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file* tmp = (t_file *)files;

	if (flags->big_r)
		print_all_things(files, flags, conf);
	else
		print_things(flags, files, conf);
	print_column(NULL, NULL, NULL, conf);
}
