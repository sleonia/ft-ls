#include "parser/parser.h"

bool		read_folders(t_folder *folders, const char **args)
{
	if (!args)
	{
		folders->folder_name = ft_strdup("./");
		folders->fd = opendir("./");
	}
	else
	{
		//do something
	}
	return (true);
}