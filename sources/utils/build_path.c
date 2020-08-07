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


	result = NULL;
	result = ft_strdup(file->name);
	buf = NULL;

	file_counter = file;

	if (file->origin)
	{
		if (result[0] != '/')/////check for segv on result == NULL;
			buf = ft_strjoin("/", result);
		else
			buf = ft_strdup(result);
		ft_strdel(&result);

		if (!ft_strequ(file_counter->origin->full_path,"/"))
			result = ft_strjoin(file_counter->origin->full_path, buf);
		else
			result = ft_strdup(buf);
		ft_strdel(&buf);
		file_counter = file_counter->origin;////this is useless maybe delete
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
