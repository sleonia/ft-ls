#include "output/output.h"
#include "types.h"

/*!
* \file
* \brief
*/

void 		errno_exit(void)
{
	perror(strerror(errno));
	exit(0);
}

static bool should_print(const char *name, const bool flag_a)
{
	if (ft_strequ(name, ".") || ft_strequ(name, ".."))
		return (flag_a ? true : false);
	return (true);
}

void 		print_all_things(t_file *file, const t_flags *flags)
{
	//int 	num_dirs; //for what?
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
		if (should_print(tmp->name, flags->a))
		{
			if (tmp->name)
			{
				print_file((const t_file*)tmp, flags, tmp->next ? true : false);
			}
			//if (tmp->next)
			//	ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void 		print_file(const t_file *file, const t_flags *flags, const bool is_next)
{
	//if (flags->)
	//print_with_color(&file->stat, file->name);
	if (flags->l || flags->g)
		print_all_info(&file->stat, flags->g, (const char *)file->name);
	else
	{
		printf("%s", file->name);
		if (flags->one)
			printf("\n");
		else
		{	
			if (is_next && flags->m)
				printf(", ");
			else if (is_next)
				printf(", ");
			else
				printf("\n");
		}
	}
}

void			print(const t_flags *flags, const t_file *files)
{ //del this later or rename
	t_file* tmp = (t_file *)files;

	if (!flags->big_r)
	{
		//ft_putstr("total "); //ls -l total doesnt working
		//ft_putnbr(tmp->stat.st_blksize);
		//ft_putchar('\n');
		print_directory(files->files_inside, (const t_flags*)flags);
	}
	else
		print_all_things((t_file *)files, flags); //change to const t_file files in declaration in func
}