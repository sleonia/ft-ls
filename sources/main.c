#include "types.h"
#include "parser/parser.h"

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_folder	*folders;

	if (!parser((const char **)av, folders, flags))
		return (1);
	//run any processing flags
	return (0);
}
