#include "parser/parser.h"
#include "print/print.h"

/*!
**	\file
**	\brief Read flags, validate and collect them.
**	\return index in user input that equals folder or error flag
*/

static bool	has_no_flags(t_flags *flags) {
	if (flags->a || flags->l || flags->big_r || flags->little_r
		|| flags->g || flags->t || flags->m || flags->f)
		return (false);
	return (flags->no_flags = true);
}

int			read_flags(t_flags *flags, const char **args, int ac) {
	int		i;

	if (ac == 1)
		return (1);
	i = 0;
	while (args[++i]) {
		if (validate_flags(flags, args[i])) {
			if (i)
				i--;
			break ;
		}
	}
	flags->no_flags = has_no_flags(flags);
	return (i);
}
