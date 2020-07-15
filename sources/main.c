#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "output/output.h"
#include "sort/sort.h"

/*!
* \file
* \brief Main file
*	How if works:
*		1. Init structs
*		2. Parsing input agruments by flags and folders
*		3. Processing flags
*		4. Print result
*/

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file		*files;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (1);
	if (!parser((const char **)av, files, flags, ac))
		return (1);
	if (flags->t || flags->little_r)
		sort((const t_flags*)flags, &files);
	print((const t_flags*)flags, (const t_file*)files);
	return (0);
}
