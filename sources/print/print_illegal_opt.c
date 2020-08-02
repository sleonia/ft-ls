#include "print/print.h"

/*!
** \file
** \brief
*/

void		print_illegal_opt(const char symb)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(symb);
	ft_putstr("\n\
usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n");
}