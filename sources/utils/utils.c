#include "utils/utils.h"
#include "libft.h"

/*!
* \file
* \brief
*/

t_flags		*init_flags(void)
{
	t_flags	*flags;

	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	return (flags);
}

t_file 		*init_file(void)
{
	t_file 	*files;

	if (!(files = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	return (files);
}

t_file			*new_file(t_file *prev)//this didnt work with void because of a copy of pointer being sent as arg inside of the actual pointer thus the resulted *file leaked while staying NULL
{
	t_file 	*file;

	if (!(file = init_file()))
		return (NULL);
	if (prev)
	{
		prev->next = file;
		file->prev = prev;
	}
	return (file);
}

char *build_path(t_file *file)//////this shit will break on a file with no name, this is intended, don't fix it
{
	char *buf;
	char *result;
	t_file *file_counter;


	result = ft_strdup(file->name);////protect me
	file_counter = file;
	if (file->origin)
	{
		while (file_counter->origin)
		{
			buf = ft_strjoin("/", result);/////protect me but first check if it's needed
			ft_strdel(&result);
			result = ft_strjoin(file_counter->origin->name, buf);/////protect me
			ft_strdel(&buf);
			file_counter = file_counter->origin;
		}
	}
	return (result);
}

char *build_path_for_arg(const char *name)
{
	char *result;

	result = ft_strjoin("./", name);///protect me
	return (result);
}