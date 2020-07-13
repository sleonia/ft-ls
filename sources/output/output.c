#include "output/output.h"
#include "types.h"

void        print_illegal_opt(const char symb)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(symb);
	ft_putstr("\n\
usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n");
}

void 		errno_exit(void)
{
	perror(strerror(errno));
	exit(0);
}

static bool should_print(t_file *file, t_flags *flags)
{
	if (ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))
	{
		if (flags->a)
			return (true);
		return (false);
	}
	return (true);
}

void 		print_all_things(t_file *file, t_flags *flags)
{
	int 	num_dirs;
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags);
	while (counter)
	{
		if (!ft_strequ(counter->name, ".") && !ft_strequ(counter->name, "..") && counter->is_directory)
		{
			ft_putendl(counter->full_path);///////плюс двоеточие
			print_all_things(counter, flags);
		}

		counter = counter->next;
	}
}

void 		print_directory(t_file *file, t_flags *flags)
{
	t_file *counter;

	counter = file;
	while(counter)
	{
		if (should_print(counter, flags))
			print_file(counter, flags);
		counter = counter->next;
	}
}

void 		print_file(t_file *file, t_flags *flags)
{
	ft_putendl(file->name);
}