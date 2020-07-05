#include "parser/parser.h"
#include "utils/utils.h"

/*
	Tests:

	./ft-ls -9					-> KO
	./ft-ls -a					-> OK
	./ft-ls -a ../				-> OK
	./ft-ls -aR ../				-> OK
	./ft-ls -aR1 ../			-> OK
	./ft-ls -aR1554 ../			-> KO
	./ft-ls -aR1 ../ -a			-> OK
	./ft-ls -aR1 ../ ./ -a		-> OK
*/



bool			parser(const char **av, t_folder *folders, t_flags *flags)
{
	int			index;

	index =	read_flags(flags, av);
	read_folders(index, folders, av);
	return (true);
}
