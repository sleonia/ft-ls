#include "parser/parser.h"
#include "utils/utils.h"
#include <errno.h>

static void	fill_file(const char *name, t_file *file)
{
	struct stat test;

	ft_memset(&test, 0, sizeof(struct stat));
	if (stat(name, &test))
	{
		//char *error = strerror(errno);
		return ;///////this should be dealt with accordingly
	}


	file->name = (char *)name;


	////get stat and check file type first
	////then deal accordingly
	if (S_ISDIR(test.st_mode))
	{
		file->is_folder = true;
		file->fd = opendir(name);
	}

//	struct dirent *test = readdir(file->fd);
//	printf("%s\n", test->d_name);
//	struct stat *test2;
	/*if (!stat(folder->name, test2))
		printf("stat went wrong\n");
	struct stat *test3;
	if (!lstat(folder->name, test3))
		printf("lstat went wrong\n");*/

}

bool		read_files(int index, t_file *files, const char **args, int ac)
{
	t_file *tmp;

	tmp = files;
//	if (!args)
//		fill_folder("./", folders);
//	see read_flags comment for the same thing
//	can it be done using index instead?
	if (ac == 1)
		fill_file("./", files);
	else
	{
		while (args[index++])
		{
			fill_file(args[index], tmp);
			new_file(tmp);
			tmp = tmp->next;
		}
	}
	return (true);
}