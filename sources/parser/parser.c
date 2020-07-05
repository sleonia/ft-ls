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



bool			parser(const char **av, t_file *files, t_flags *flags, int ac)
{
	int			index;

	index =	read_flags(flags, av, ac);
	read_files(index, files, av, ac);
	return (true);
}
