#include "parser/parser.h"
#include "output/output.h"

/*
*	Read flags, validate and collect them.
*	\return index in user input that equals folder or error flag
*/

int			read_flags(t_flags *flags, const char **args)
{
	int 	i;
	int		index;
	int		old_index;

	if (!args)
		return (1);
	i = 0;
	old_index = 1;
	while (args[++i])
	{
		index = validate_flags(flags, args[i]);
		old_index = old_index > index ? old_index : index;
	}
	printf("%d\n", old_index);
	return (old_index);
}