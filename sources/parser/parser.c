#include "parser/parser.h"
#include "utils/utils.h"

/*
	Tests:

	ft_ls -9					-> KO
	ft_ls -a					-> OK
	ft_ls -a ../				-> OK
	ft_ls -aR ../				-> OK
	ft_ls -aR1 ../				-> OK
	ft_ls -aR1554 ../			-> KO
	ft_ls -aR1 ../ -a			-> OK
	ft_ls -aR1 ../ ./ -a		-> OK
*/



bool			parser(const char **av, t_folder *folders, t_flags *flags)
{
	read_flags(flags, av);
	read_folders(folders, av);
	return (true);
}
