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

void 		print_files_test(t_file *file, t_flags *flags)
{
	t_file *counter;
	t_file *origin;
	bool	done;

	done = false;
	origin = file;
	counter = origin->files_inside;
	while (!done)
	{
		if (!counter)
		{
			done = true;
			break;
		}
		if (!counter->name)
		{
			/////this here is a **hack** delete it when you get rid of empty elements in file lists
			done = true;
			break;
		}
		if (!ft_strequ(counter->name, ".") && !ft_strequ(counter->name, "..") && !flags->a)
			ft_putendl(counter->name);
		counter = counter->next;
	}
}