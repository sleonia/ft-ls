#include "utils/utils.h"

/*!
** \file
** Example of link:
**		Network -> /System/Volumes/Data/Network
*/

void	print_link_value(const char *full_path) {
	int		size;
	char	buf[PATH_MAX];

	size = readlink(full_path, buf, PATH_MAX);
	buf[size] = '\0';
	ft_printf(" -> %s", buf);
}
