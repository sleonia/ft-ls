#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"

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
	t_folder	*folders;

	if (!(flags = init_flags()))
		return (1);
	if (!(folders = init_folder()))
		return (1);
	if (!parser((const char **)av, folders, flags))
		return (1);
	return (0);
}
