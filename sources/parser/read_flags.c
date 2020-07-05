#include "parser/parser.h"
#include "output/output.h"

/*
*	Read flags and validate them
*	When an error occurs print usage and return NULL
*/

bool		read_flags(t_flags *flags, const char **args)
{
	int 	i;
	int		k;

	if (!args)
		return (NULL);
	i = -1;

	while (args[++i])
	{
		k = validate_flags(flags, args[i]);
		if (k)
		{
			//
		}

	}
	return (true);	
}