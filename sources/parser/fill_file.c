#include "parser/parser.h"
#include "utils/utils.h"
#include "print/print.h"

void			del_last(t_file *prev, t_file *curr)
{
	prev->next = NULL;
	ft_memdel((void **)&curr);
}

static bool		directory_to_ignore(t_file *file, t_flags *flags)
{
	int		depth;
	t_file	*depth_counter;

	depth = 0;
	if (file->name[0] == '.' && !file->no_ignore)
		return (!(file->no_ignore = false));
	if (!flags->big_r)
	{
		depth_counter = file;
		while (depth_counter)
		{
			depth++;
			depth_counter = depth_counter->origin;
		}
		if (depth > 1)
			return (true);
	}
	return (false);
}

static void		fill_files_inside_dir(t_file *file, t_flags *flags)
{
	t_file	*tmp;
	t_file	*prev;

	tmp = NULL;
	tmp = new_file(tmp);
	file->files_inside = tmp;
	tmp->origin = file;
	while (tmp)
	{
		if (!(tmp->dirent = readdir(file->fd)))
		{
			if (errno)
				ft_printf("ft_ls: %s\n", strerror(errno));
			break ;
		}
		fill_file(tmp->dirent->d_name, tmp, flags);
		take_config(tmp->name, &tmp->stat, flags, tmp->origin->conf);
		prev = tmp;
		tmp = new_file(tmp);
		tmp->origin = file;
	}
	if (!tmp->name)
		del_last(prev, tmp);
}

static void		fill_directory(t_file *file, const char *name, t_flags *flags)
{
	t_file	*file_counter;

	file_counter = file;
	file_counter->fd = opendir(name);
	if (!file_counter->fd)
		return ;
	if (!directory_to_ignore(file_counter, flags))
	{
		if (!file->conf)
			file->conf = new_conf();
		errno = 0;
		fill_files_inside_dir(file_counter, flags);
	}
	if (file_counter->fd)
		closedir(file_counter->fd);
	file_counter->fd = NULL;
}

void			fill_file(const char *name, t_file *file, t_flags *flags)
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
