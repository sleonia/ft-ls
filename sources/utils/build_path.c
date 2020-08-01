#include "utils/utils.h"
#include "libft.h"

/*!
** \file
** \brief
*/

char	*build_path(t_file *file)
{
	char *buf;
	char *result;
	t_file *file_counter;


	result = ft_strdup(file->name);
	file_counter = file;
	if (file->origin)
	{
		while (file_counter->origin)
		{
			buf = ft_strjoin("/", result);
			ft_strdel(&result);
			result = ft_strjoin(file_counter->origin->name, buf);
			ft_strdel(&buf);
			file_counter = file_counter->origin;
		}
	}
	return (result);
}

char	*build_path_for_arg(const char *name)
{
	char *result;

	result = ft_strjoin("./", name);
	return (result);
}
