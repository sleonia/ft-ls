#include "parser/parser.h"
#include "utils/utils.h"

/*!
* \file
* \brief Main func of parser. Call parsing flags and files
* \return t_conf struct with config for output or NULL
*/

t_conf			*parser(const char **av, t_file *files, t_flags *flags, int ac)
{
	t_conf		*conf;
	int			index;

	index =	read_flags(flags, av, ac);
	conf = read_files(index, files, av, flags);
	return (conf ? conf : NULL);
}
