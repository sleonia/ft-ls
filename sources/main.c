#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "output/output.h"
#include "sort/sort.h"

/*!
** \file
** \brief Main file
**	How if works:
**		1. Init structs
**		2. Parsing input agruments by flags
**		3. Parsing input agruments by folders
**			calculate sizes for output
**		4. If -r or -t flags -> sort
**		5. Print result
*/

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file		*files;
	t_conf		*conf;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (1);
	if (!(conf = parser((const char **)av, files, flags, ac)))
		return (1);
	sort((const t_flags*)flags, files);
	print((const t_flags*)flags, (const t_file*)files, (const t_conf*)conf);
	return (0);
}
