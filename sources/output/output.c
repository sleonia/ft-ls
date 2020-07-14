#include "output/output.h"
#include "types.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

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
			ft_putendl(counter->full_path);///////плюс двоеточие
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
			if (tmp->next)
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

/*!
*	Example of ctime(&file->stat.st_mtime) -> Tue Jul 14 02:36:07 2020
*/

static void	print_time(const t_file *file)
{
	char	ftime[13];
	char	*tmptime;
	int		i;

	tmptime = ctime(&(file->stat.st_ctime)) + 4;
	ft_memset(ftime, ' ', sizeof(ftime));
	ftime[0] = tmptime[4];
	ftime[1] = tmptime[5];
	ftime[3] = tmptime[0];
	ftime[4] = tmptime[1];
	ftime[5] = tmptime[2];
	ftime[12] = 0;
	i = 6;
	while (++i < 12)
		ftime[i] = tmptime[i];
	ft_putstr(ftime);
	ft_putchar(' ');
}

void		print_all_info(const t_file *file)
{
	ft_putstr("-rw-r--r-- "); //print rights
	ft_putnbr(file->stat.st_nlink);
	ft_putchar(' ');
	ft_putstr((getpwuid(file->stat.st_uid))->pw_name);
	ft_putchar(' ');
	ft_putstr(getgrgid(file->stat.st_gid)->gr_name);
	ft_putchar(' ');
	ft_putnbr(file->stat.st_size);
	ft_putchar(' ');
	print_time(file);
	ft_putchar(' ');
	ft_putstr(file->name);
}

void 		print_file(const t_file *file, const t_flags *flags)
{
	if (flags->l)
		print_all_info(file);
	else
		ft_putstr(file->name);
}