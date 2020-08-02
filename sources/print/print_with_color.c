#include "print/print.h"
#include <sys/stat.h>

/*!
** \file
** \brief
*/

void			print_with_color(const struct stat *stat_, const char *name)
{
	if (S_ISDIR(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_BOLD_CYAN, name, ANSI_COLOR_RESET);
	else if (S_ISLNK(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_MAGENTA, name, ANSI_COLOR_RESET);
	else if (S_ISSOCK(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_YELLOW, name, ANSI_COLOR_RESET);
	else if (S_ISFIFO(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_GREEN, name, ANSI_COLOR_RESET);
	else if (S_ISBLK(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_BOLD_GREEN, name, ANSI_COLOR_RESET);
	else if (S_ISCHR(stat_->st_mode))
		ft_printf("%s%s%s", ANSI_COLOR_BLUE, name, ANSI_COLOR_RESET);
	else if (S_ISREG(stat_->st_mode) && stat_->st_mode & S_IXUSR)
		ft_printf("%s%s%s", ANSI_COLOR_RED, name, ANSI_COLOR_RESET);
	else
		ft_printf("%s", name);
}