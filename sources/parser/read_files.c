#include "parser/parser.h"
#include "utils/utils.h"
#include "output/output.h"

static bool	directory_to_ignore(t_file *file, t_flags *flags)
{
	int depth;
	t_file *depth_counter;

	depth = 0;
	if (ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))//////maybe something else will be added
		return (file->ignore = true);
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
		fill_file(file_counter->dirent->d_name, file_counter, flags);
		file_counter = new_file(file_counter);
		file_counter->origin = file;
	}
}

static void fill_directory(t_file *file, const char *name, t_flags *flags)
{
	t_file 			*file_counter;

	file_counter = file;///might be useless but let it stay for now for segv-safety reasons
	file_counter->is_directory = true;
	file_counter->fd = opendir(name);
	if (!directory_to_ignore(file_counter, flags))
		fill_files_inside_dir(file_counter, flags);
}


static void fill_non_directory(t_file *file, const char *name)
{
	t_file 	*file_counter;

	file_counter = file;
	file_counter->is_directory = false;
}

void	fill_file(const char *name, t_file *file, t_flags *flags)
{
	struct stat	file_stat;
	if (!file->name)
		file->name = ft_strdup(name);////protect me and do a ft_strdup unless you make sure you don't lose the pointer, caught a segv here with previous version
	if (!file->full_path)
		file->full_path = build_path(file);
	ft_memset(&file_stat, 0, sizeof(struct stat));
	if (stat(file->full_path, &file_stat))
		errno_exit();
	file->stat = file_stat;
	if (S_ISDIR(file_stat.st_mode))
		fill_directory(file, file->full_path, flags);
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


bool		read_files(int index, t_file *files, const char **args, int ac, t_flags *flags)
{
	t_file *tmp;

	tmp = files;
	printf("%s\n", args[index]);
	if (!args[index]) {
		fill_file("./", files, flags);
	}
	//else {
	//}


	//if (!has_args(args, ac))////ac == 1 doesnt work for cases when flags are several arguments, thus a different check should be at work,
	//also wont checking args[index + 1] trigger hate from amatilda and other mad unix-wankers? valgrind will surely say something they'll be happy to see :/
	//lol also !args[index + 1] triggers on "ls directory_name" and starts reading current directory instead of a specified one D:
	//i suggest a bool flag "has_args" and add a check for that (see flag "no_flags" in flags structure)
	//this will make it way easier
	//{
		//fill_file("./", files, flags);
	//}
//
	else
	{
		if (flags->no_flags)
			index--;
		while (args[index]/*args[++index]*/)////so at "ls directory_name" index == 1 so we try to read from args[2] right away, losing args[1] filename D:< anyway if we dont checking args[++] will return NOT NULL
		//and lol THEN it will actually do the ++ thing which leads to attempt to read from NULL and an obvious segv. FOR NOW it works like this, needs more tests
		{
			tmp->full_path = build_path_for_arg(args[index]);
			fill_file(args[index], tmp, flags);
			new_file(tmp);//////don't forget to clean this shit in case we have one arg, unix-trigger boyz won't get us this easy!
			tmp = tmp->next;
			index++;
		}
	}
	return (true);
}