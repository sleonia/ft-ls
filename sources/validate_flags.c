#include "ftls.h"

int validate_flags(char *arg)
{
	int i;
	char *actual_arg;
	int len;

	i = 0;
	if (!arg)
		return (1);///arg = NULL
	if (!(actual_arg = ft_strtrim(arg)))
		return (2);/////strtim failed
	len = ft_strlen(arg);
/////deal with whitespaces
	if (ft_strlen(arg) < 2)
		return (3);////search for directory with this name
	if (arg[0] != '-')
		return (4);//////not a flag
	while (arg[++i])
	{
		if (arg[i] != 'l' && arg[i] != 'R' && arg[i] != 'a' && arg[i] != 'r'
		&& arg[i] != 't')
			return (false);
	}
	return (0);
}