#include "parser/parser.h"
#include "utils/utils.h"

/*!
** \file
** \brief	Main func of parser. Call parsing flags and files.
** \return	t_conf* struct with config for output or NULL
*/

bool		parser(const char **av, t_file *files, t_flags *flags, int ac)
{
	int			index;

	index =	read_flags(flags, av, ac);
	read_files(index, files, av, flags);
	return true;
}
