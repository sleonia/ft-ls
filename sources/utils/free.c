#include "types.h"
#include "utils.h"
#include "libft.h"

static void free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->files_inside)
		free_file(file->files_inside);
	if (file->next)
		free_file(file->next);
	ft_strdel(&file->name);
	ft_strdel(&file->full_path);
	if (file->fd)
		closedir(file->fd);
	free(file);
	file = NULL;
}

void free_all(t_file *files, t_conf *conf, t_flags *flags)
{

	if (conf)
		free(conf);
	if (flags)
		free(flags);
	free_file(files);
	exit(0);
}