#include "parser/parser.h"
#include "utils/utils.h"

bool			parser(const char **av, t_file *files, t_flags *flags, int ac)
{
	int			index;

	index =	read_flags(flags, av, ac);
	printf("%d\n", index);
	read_files(index, files, av, ac, flags);
	return (true);
}
