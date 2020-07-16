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

void 		print_all_things(const t_file *file, const t_flags *flags, const t_conf *conf)
{
	//int 	num_dirs; //for what?
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags, conf);
	while (counter)
	{
		if (!ft_strequ(counter->name, ".") && !ft_strequ(counter->name, "..") && counter->is_directory)
		{
			printf("%s\n", counter->full_path);///////плюс двоеточие
			print_all_things(counter, flags, conf);
		}

		counter = counter->next;
	}
}

void 		print_directory(const t_file *file, const t_flags *flags, const t_conf *conf)
{
	t_file *tmp;

	tmp = (t_file *)file;
	if (flags->l || flags->g)
		printf("total: %d\n", conf->total);
	while(tmp)
	{
		if (should_print(tmp->name, flags->a))
		{
			if (tmp->name)
			{
				print_file((const t_file*)tmp, flags, tmp->next ? true : false, conf);
			}
			//if (tmp->next)
			//	ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

void 		print_file(const t_file *file, const t_flags *flags, const bool is_next, const t_conf *conf)
{
	if (flags->l || flags->g)
		print_all_info(&file->stat, conf, flags->g, (const char *)file->name);

	//printf("%llu ", file->stat.st_ino); //for -i flag
	else
	{
		print_with_color((const struct stat*)&file->stat, (const char*)file->name);
		if (flags->one)
			printf("\n");
		else
		{	
			if (is_next && flags->m)
				printf(", ");
			else if (is_next)
				printf(" ");
			else
				printf("\n");
		}
	}
}

void			print(const t_flags *flags, const t_file *files, const t_conf *conf)
{
	t_file* tmp = (t_file *)files;

	if (flags->big_r)
		print_all_things((const t_file *)files, flags, conf);
	else
		print_directory(files->files_inside, (const t_flags*)flags, conf);
}
