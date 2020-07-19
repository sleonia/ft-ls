#include "parser/parser.h"
#include "utils/utils.h"
#include "output/output.h"

/*!
** \file
** \brief //?
*/

static bool	directory_to_ignore(t_file *file, t_flags *flags)
{
	int depth;
	t_file *depth_counter;

	depth = 0;
	if ((ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))
	&& !file->no_ignore)//////maybe something else will be added
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
	bool	done;

	file_counter = NULL;
	done = false;
	file_counter = new_file(file_counter);///protect
	file->files_inside = file_counter;
	file_counter->origin = file;
	while(!done)
	{
		if (!(file_counter->dirent = readdir(file->fd)))
		{
			done = true;
			break;////check leak, empty entry created?
		}
		fill_file(file_counter->dirent->d_name, file_counter, flags, conf);
		file_counter = new_file(file_counter);
		file_counter->origin = file;
	}
	if (!file_counter->name)
	{
		free(file_counter);
		file_counter = NULL;///this is nice but not NECESSARY
	}
}

static void fill_directory(t_file *file, const char *name, t_flags *flags, t_conf *conf)
{
	t_file 			*file_counter;

	file_counter = file;///might be useless but let it stay for now for segv-safety reasons
	file_counter->is_directory = true;
	file_counter->fd = opendir(name);
	if (!directory_to_ignore(file_counter, flags))
		fill_files_inside_dir(file_counter, flags, conf);
}


static void fill_non_directory(t_file *file, const char *name)
{
	t_file 	*file_counter;

	file_counter = file;
	file_counter->is_directory = false;
}

void	fill_file(const char *name, t_file *file, t_flags *flags, t_conf *conf)
{
	struct stat	stat_;

	if (!file->name)
		file->name = ft_strdup(name);////protect me and do a ft_strdup unless you make sure you don't lose the pointer, caught a segv here with previous version
	if (!file->full_path)
		file->full_path = build_path(file);
	ft_memset(&stat_, 0, sizeof(struct stat));
	if (stat(file->full_path, &stat_) < 0)
	{
		//printf ("%s\n", file->name);
		errno_exit();
	}
	file->stat = stat_;
	if (flags->t || flags->little_r)
		file->time = stat_.st_mtime;
	take_config(name, &file->stat, conf);
	if (S_ISDIR(stat_.st_mode))
		fill_directory(file, file->full_path, flags, conf);
	else
		fill_non_directory(file, name);
}

/*
 * PARSE THIS LOL
 */
static bool has_args(char **args, int ac/*or whatever else is needed maybe flags i don't know*/)
{
	////this checks if we have specified files given as args
	////return true if we do
	////return false if we should read from "./"
	return (true);
}


t_conf		*read_files(int index, t_file *files, const char **args, t_flags *flags)
{
	t_conf	*conf;
	t_file	*tmp;

	tmp = files;
	if (!(conf = new_conf()))
		return (NULL);
	if (!args[index]) {
		fill_file("./", files, flags, conf);
	}
	else
	{
		if (flags->no_flags) //maybe del this
			index--;
		while (args[++index])
		{
			tmp->no_ignore = true;
			tmp->full_path = build_path_for_arg(args[index]);
			fill_file(args[index], tmp, flags, conf);
			new_file(tmp);//////don't forget to clean this shit in case we have one arg, unix-trigger boyz won't get us this easy!
			tmp = tmp->next;
//			index++;
		}
		if (!tmp->name)
			ft_memdel((void **)&tmp);
	}
	return (conf);
}