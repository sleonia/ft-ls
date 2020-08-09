/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:49:26 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:50:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include <sys/stat.h>

/*
** \file
** \brief
*/

void			print_with_color(const mode_t st_mode,
					const char *name, int width)
{
	if (S_ISDIR(st_mode))
		ft_printf("%s", ANSI_COLOR_BOLD_CYAN);
	else if (S_ISLNK(st_mode))
		ft_printf("%s", ANSI_COLOR_MAGENTA);
	else if (S_ISSOCK(st_mode))
		ft_printf("%s", ANSI_COLOR_YELLOW);
	else if (S_ISFIFO(st_mode))
		ft_printf("%s", ANSI_COLOR_GREEN);
	else if (S_ISBLK(st_mode))
		ft_printf("%s", ANSI_COLOR_BOLD_GREEN);
	else if (S_ISCHR(st_mode))
		ft_printf("%s", ANSI_COLOR_BLUE);
	else if (S_ISREG(st_mode) && st_mode & S_IXUSR)
		ft_printf("%s", ANSI_COLOR_RED);
	ft_printf("%-*s", width == 0 ? 1 : width, name);
	ft_printf("%s", ANSI_COLOR_RESET);
}
