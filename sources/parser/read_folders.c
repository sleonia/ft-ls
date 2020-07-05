#include "parser/parser.h"
#include "utils/utils.h"
#include "output.h"

static void	fill_file(const char *name, t_file *file)
{
	struct stat test;
	struct dirent *test2;

	ft_memset(&test, 0, sizeof(struct stat));
	if (stat(name, &test))
		errno_exit();
	file->name = (char *)name;
	////get stat and check file type first
	////then deal accordingly
	if (S_ISDIR(test.st_mode))
	{
		file->is_folder = true;
		file->fd = opendir(name);
		test2 = readdir(file->fd);
		printf("%s\n", test2->d_name);
	}
}

bool		read_files(int index, t_file *files, const char **args, int ac)
{
	t_file *tmp;

	tmp = files;
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