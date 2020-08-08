#include "parser/parser.h"
#include "utils/utils.h"
#include "print/print.h"
#include "ft_printf.h"

/*
** \file
** \brief
*/

static bool	directory_to_ignore(t_file *file, t_flags *flags)
{
	int depth;
	t_file *depth_counter;

	depth = 0;
	if (file->name[0] == '.' && !file->no_ignore)
		return (!(file->no_ignore = false));
	if (!flags->big_r)
	{
		depth_counter = file;
		while(depth_counter)
		{
			depth++;
			depth_counter = depth_counter->origin;
		}
		if (depth > 1)
			return (true);
	}
	return (false);
}

static void fill_files_inside_dir(t_file *file, t_flags *flags)
{
	t_file *file_counter;
	t_file *prev;
	bool	done;

	file_counter = NULL;
	done = false;
	file_counter = new_file(file_counter);
	file->files_inside = file_counter;
	file_counter->origin = file;
	while(!done)
	{
		errno = 0;
		if (!(file_counter->dirent = readdir(file->fd)))
		{
			if (errno)
				ft_printf("ft_ls: %s\n",strerror(errno));
			done = true;
			break;
		}
		fill_file(file_counter->dirent->d_name, file_counter, flags);
		take_config(file_counter->name, &file_counter->stat, flags, file_counter->origin->conf);
		prev = file_counter;
		file_counter = new_file(file_counter);
		file_counter->origin = file;
	}
	if (!file_counter->name)
	{
		prev->next = NULL;
		free(file_counter);
		file_counter = NULL;
	}
}

static void fill_directory(t_file *file, const char *name, t_flags *flags)
{
	t_file 			*file_counter;

	file_counter = file;
	file_counter->fd = opendir(name);
	if (!file_counter->fd)
		return ;////check if we should print error here or not
	if (!directory_to_ignore(file_counter, flags))
	{
		if (!file->conf)
			file->conf = new_conf();

		//take_config(name, &file->stat, file->conf);///full path				///////maybe del
		//take_config(file->full_path, &file->stat, file->conf);///full path	///////maybe del
		fill_files_inside_dir(file_counter, flags);
	}

	if (file_counter->fd)
		closedir(file_counter->fd);
	file_counter->fd = NULL;
}

void	fill_file(const char *name, t_file *file, t_flags *flags)
{
	if (!file->name)
		file->name = ft_strdup(name);
	if (!file->full_path)
		file->full_path = build_path(file);
	if (lstat(file->full_path, &file->stat) < 0)
	{
		ft_printf("ft_ls: %s: %s\n", file->name, strerror(errno));
		file->is_error = true;
		return ;
	}
	file->type = get_type(file->stat.st_mode);
	if (file->type == Directory)
		fill_directory(file, file->full_path, flags);
}

void		read_files(int index, t_file *files, const char **args, t_flags *flags)
{
	t_file	*tmp;
	t_file 	*prev;

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
		{
			prev->next = NULL;
			ft_memdel((void **) &tmp);
		}
	}
}