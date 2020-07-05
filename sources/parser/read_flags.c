#include "parser/parser.h"
#include "output/output.h"

/*
*	Read flags and validate them
*	When an error occurs print usage and return NULL
*/

t_flags 	*read_flags(const char **args)
{
	t_flags	*flags;
	int 	i;

	if (!args)
		return (NULL);
	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	i = -1;
	while (args[++i])
	{
		if (validate_flags(flags, args[i])) //func for check -a -5645 or ./folder/
		{
			
		}

	}

	i = 0;
	//while (args[++i])
		//collect_flags(flags, args[i]);
	return (flags);
}