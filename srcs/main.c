#include "ftls.h"

int main(int ac, char **av)
{
	t_flags *flags;
	t_folder *folders;

	if (!(flags = read_flags(av[1])))
		return (-1);//////change this to actually print error
	if (!(folders = read_folders(flags, ac, av)))
		return (-1);////deal with printing errors again
	print_things(flags, folders);

//	free_stuff(/*change arg to stuff to free*/);
//	remember: no exit

	return (0);
}