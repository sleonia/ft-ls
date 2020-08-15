#include "print/print.h"

/*!
** \file
** \brief Print illegal option
*/

void		print_illegal_opt(const char symb) {
	ft_putstr("ls: illegal option -- ");
	ft_putchar(symb);
	ft_putstr("\nusage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n");
}
