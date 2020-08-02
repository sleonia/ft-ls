#include "parser/parser.h"
#include "utils/utils.h"
#include "print/print.h"

/*!
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

static void fill_files_inside_dir(t_file *file, t_flags *flags, t_conf *conf)
{
	t_file *file_counter;
	t_file *sleonia_i_tut_slomal;
	bool	done;

	file_counter = NULL;
	done = false;
	file_counter = new_file(file_counter);
	file->files_inside = file_counter;
	file_counter->origin = file;
	while(!done)
	{
		if (!(file_counter->dirent = readdir(file->fd)))
		{
			done = true;
			break;
		}
		fill_file(file_counter->dirent->d_name, file_counter, flags, conf);
		sleonia_i_tut_slomal = file_counter;
		file_counter = new_file(file_counter);
		file_counter->origin = file;
	}
	if (!file_counter->name)
	{
		sleonia_i_tut_slomal->next = NULL;
		free(file_counter);
		file_counter = NULL;
	}
}

static void fill_directory(t_file *file, const char *name, t_flags *flags, t_conf *conf)
{
	t_file 			*file_counter;

	file_counter = file;
	file_counter->fd = opendir(name);
	if (!directory_to_ignore(file_counter, flags))
		fill_files_inside_dir(file_counter, flags, conf);
}


static void fill_non_directory(t_file *file, const char *name)
{
	t_file 	*file_counter;

	file_counter = file;
}

void	fill_file(const char *name, t_file *file, t_flags *flags, t_conf *conf)
{
	struct stat	stat_;

	if (!file->name)
		file->name = ft_strdup(name);
	if (!file->full_path)
		file->full_path = build_path(file);
	ft_memset(&stat_, 0, sizeof(struct stat));
	if (stat(file->full_path, &stat_) < 0)
	{
		if (lstat(file->full_path, &stat_) < 0)
		{
			ft_printf("ft_ls: %s: %s\n", file->name, strerror(errno));
			file->is_error = true;
			return ;
		}
	}
	file->stat = stat_;
	file->time = stat_.st_mtime;
	take_config(name, &file->stat, conf);
	file->type = get_type(stat_.st_mode);
	if (file->type == Directory)
		fill_directory(file, file->full_path, flags, conf);
	else
		fill_non_directory(file, name);
}

t_conf		*read_files(int index, t_file *files, const char **args, t_flags *flags)
{
	t_conf	*conf;
	t_file	*tmp;
	t_file 	*sleonia_vse_polomal;

	tmp = files;
	if (!(conf = new_conf()))
		return (NULL);
	if (!args[index])
	{
		files->no_ignore = true;
		fill_file("./", files, flags, conf);
	}
	else
	{
		if (flags->no_flags)
			index = 0;
		while (args[++index])
		{
			tmp->no_ignore = true;
			tmp->full_path = build_path_for_arg(args[index]);
			fill_file(args[index], tmp, flags, conf);
			sleonia_vse_polomal = tmp;
			tmp = new_file(tmp);
		}
		if (!tmp->name)
		{
			sleonia_vse_polomal->next = NULL;
			ft_memdel((void **)&tmp);
		}

	}
	return (conf);
}