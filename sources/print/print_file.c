/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:48:02 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 21:05:52 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>

/*
** \file
** \brief
*/

void		print_file(const t_file *file, const t_flags *flags, bool is_next)
{
	if (flags->i)
		ft_printf("%*llu ", file->origin->conf->inode_nbr_len + 1,
				file->stat.st_ino);
	if (flags->l || flags->g)
		print_all_info(file, flags);
	else
	{
		print_with_color((const struct stat*)&file->stat,
						(const char*)file->name, 0);
		if (flags->one)
			ft_printf("\n");
		else
		{
			if (is_next && flags->m)
				ft_printf(", ");
			else if (is_next)
				ft_printf(" ");
		}
	}
}
