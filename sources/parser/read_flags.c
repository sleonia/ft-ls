#include "parser/parser.h"
#include "output/output.h"

/*!
*	Read flags, validate and collect them.
*	\return index in user input that equals folder or error flag
*/

static bool	has_no_flags(t_flags *flags)
{
	if (flags->a || flags->l || flags->big_r || flags->little_r ||
	flags->one || flags->t)
		return (false);
	return (flags->no_flags = true);
}

int			read_flags(t_flags *flags, const char **args, int ac)  //переписать логику возврата функции
{
	int 	i;
	int		index;
	int		old_index;

	if (ac == 1)
		return (1);
	i = 0;
	old_index = 1;
	while (args[++i])
	{
		index = validate_flags(flags, args[i]);
		old_index = old_index > index ? old_index : index;
	}
	flags->no_flags = has_no_flags(flags);
	printf("%d\n", old_index);/////get rid of printf
	return (old_index);
}