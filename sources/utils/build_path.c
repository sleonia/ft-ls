#include "utils/utils.h"

/*!
** \file
** \brief Create full path
**		Example of path:
**			-	"~"
**			-	"/"
**			-	"/Users/sleonia/Desktop"
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
			result = ft_strjoin(file_counter->origin->full_path, buf);///?
			ft_strdel(&buf);
			file_counter = file_counter->origin;
		}
	}
	return (result);
}

char	*build_path_for_arg(const char *name)
{
	char *result;
	char *strstr;
	char *slash;

	if (name[0] == '/')
		return (ft_strdup(name));
	strstr = ft_strstr(name, "User");
	if (!strstr)
		result = ft_strjoin("./", name);
	else
		result = ft_strdup(name);
	return (result);
}
