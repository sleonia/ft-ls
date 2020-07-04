#include "ftls.h"


t_folder *read_folders(t_flags *flags, int ac, char **av)
{
	/*
	 * ERRNO USEFUL HERE CHECK MAN FOR OPENDIR
	 */
	int	i;

	i = 1;
	t_folder *folder;

	if (!(folder = (t_folder*)ft_memalloc(sizeof(t_folder))))
		return (NULL);
	folder->fd = opendir(av[2]);
	folder->folder_name = ft_strdup(av[2]);;
}