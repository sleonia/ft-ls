#include "output/output.h"
#include "types.h"

void 		errno_exit(void)
{
	perror(strerror(errno));
	exit(0);
}

static bool should_print(t_file *file, const t_flags *flags)
{
	if (ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))
	{
		if (flags->a)
			return (true);
		return (false);
	}
	return (true);
}

void 		print_all_things(t_file *file, const t_flags *flags)
{
	int 	num_dirs;
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags);
	while (counter)
	{
		if (!ft_strequ(counter->name, ".") && !ft_strequ(counter->name, "..") && counter->is_directory)
		{
			printf("%s\n", counter->full_path);///////плюс двоеточие
			print_all_things(counter, flags);
		}

		counter = counter->next;
	}
}

void 		print_directory(t_file *file, const t_flags *flags)
{
	t_file *tmp;

	tmp = file;
	while(tmp)
	{
		if (should_print(tmp, flags))
		{
			print_file((const t_file*)tmp, flags);
			//if (tmp->next)
			//	ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void 		print_file(const t_file *file, const t_flags *flags)
{
	if (flags->l)
		print_all_info(&file->stat, (const char *)file->name);
	else
		printf("%s", file->name);
}
