#include "utils.h"

void	print_link_value(const char *name)
{
	int		size;
	char	buf[PATH_MAX];

	size = readlink(name, buf, PATH_MAX);
	buf[size] = '\0';
	ft_printf(" -> %s", buf);
}
