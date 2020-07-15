#include "output/output.h"
#include <sys/stat.h>

/*!
* \file
* \brief Print content with color
*/

void			print_with_color(const struct stat *stat, const char *name)
{
	if (S_ISDIR(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_BOLD_CYAN, name , ANSI_COLOR_RESET);
	else if (S_ISLNK(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_MAGENTA, name , ANSI_COLOR_RESET);
	else if (S_ISSOCK(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_YELLOW, name , ANSI_COLOR_RESET);
	else if (S_ISFIFO(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_GREEN, name , ANSI_COLOR_RESET);
	else if (S_ISBLK(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_BOLD_GREEN, name , ANSI_COLOR_RESET);
	else if (S_ISCHR(stat->st_mode))
		printf("%s%s%s", ANSI_COLOR_BLUE, name , ANSI_COLOR_RESET);
	else if (S_ISREG(stat->st_mode) && stat->st_mode & S_IXUSR)
		printf("%s%s%s", ANSI_COLOR_RED, name , ANSI_COLOR_RESET);
	else
		printf("%s", name);
}