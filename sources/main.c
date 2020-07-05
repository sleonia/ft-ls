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

void	FunctionForTest(t_flags *flags, t_file *files)
{ //del this later
	printf("flags: -%d -%d, -%d -%d, -%d -%d\n", flags->big_r, flags->little_r, flags->l, flags->a, flags->t, flags->one);
	
	t_file* tmp = files;
	printf("folders:\n");
	while (tmp)
	{
		printf("\t%s\n", tmp->name);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file	*files;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (1);
	if (!parser((const char **)av, files, flags, ac))
		return (1);
	FunctionForTest(flags, files);
	return (0);
}
