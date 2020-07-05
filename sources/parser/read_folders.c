#include "parser/parser.h"
#include "utils/utils.h"

static void	fill_folder(const char *name, t_folder *folder)
{
	folder->name = (char *)name;
	folder->fd = opendir(name);
}

bool		read_folders(int index, t_folder *folders, const char **args)
{
	t_folder *tmp;

	tmp = folders;
	if (!args)
		fill_folder("./", folders);
	else
	{
		while (args[index++])
		{
			fill_folder(args[index], tmp);
			new_folder(tmp);
			tmp = tmp->next;
		}
	}
	return (true);
}