#include "ftls.h"

static void collect_flags(t_flags *flags, char arg)
{
	if (arg == 'l')
		flags->l = true;
	if (arg == 'R')
		flags->big_r = true;
	if (arg == 'a')
		flags->a = true;
	if (arg == 'r')
		flags->little_r = true;
	if (arg == 't')
		flags->t = true;
}

t_flags 	*read_flags(char *arg)
{
	t_flags *flags;
	int 	i;

	if (validate_flags(arg))
	{
		///deal with error
		return (NULL);
	}

	i = 0;
	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	while (arg[++i])
		collect_flags(flags, arg[i]);
	return (flags);
}