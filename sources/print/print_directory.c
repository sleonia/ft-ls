/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:46:13 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:47:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "types.h"

/*
** \file
** \brief
*/

static bool		should_print(t_file *file, const t_flags *flags)
{
	if (file->name[0] == '.' && !file->no_ignore)
		return (flags->a ? true : false);
	return (true);
}

void			print_directory(const t_file *file, const t_flags *flags)
{
	t_file	*tmp;
	bool	is_last;

	tmp = (t_file *)file;
	if (flags->l || flags->g)
		ft_printf("total: %d\n", file->origin->conf->total);
	while (tmp)
	{
		if (should_print(tmp, flags))
		{
			if (tmp->name)
			{
				is_last = tmp->next ? true : false;
				print_file((const t_file*)tmp, flags, is_last);
			}
		}
		tmp = tmp->next;
	}
	if (!flags->l && !flags->g)
		ft_printf("\n");
}
