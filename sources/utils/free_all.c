#include "types.h"
#include "utils/utils.h"
#include "libft/libft.h"

/*!
** \file
** \brief Free all data
*/

static void	free_file(t_file *file) {
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
	ft_memdel((void **)&file->conf);
	ft_memdel((void **)&file);
}

int			free_all(t_file *files, t_flags *flags) {
	if (flags)
		free(flags);
	free_file(files);
	return (0);
}
