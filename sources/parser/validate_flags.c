#include "parser/parser.h"
#include "output/output.h"

/*!
* \file
* \brief Validate and collect all flags to t_flags struct
*/

static void collect_flags(t_flags *flags, const char arg)
{
	if (arg == 'R')
		flags->big_r = true;
	if (arg == 'r')
		flags->little_r = true;
	if (arg == 'l')
		flags->l = true;
	if (arg == 'a')
		flags->a = true;
	if (arg == 't')
		flags->t = true;
	if (arg == 'g')
		flags->g = true;
	if (arg == 'm')
		flags->m = true;
	if (arg == '1')
		flags->one = true;
}

/*!
*	\return index in user input that equals folder or error flag
*/

int		validate_flags(t_flags *flags, const char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (1);
	i = 0;
	while (arg[++i])
	{
		if (arg[i] == 'R' || arg[i] == 'r' || arg[i] == 'l' || arg[i] == 'a'
		|| arg[i] == 't' || arg[i] == 'g' || arg[i] == 'm' || arg[i] == '1')
			collect_flags(flags, arg[i]);
		else
		{
			print_illegal_opt(arg[i]);
			exit(0);
		}
	}
	return (0);
}