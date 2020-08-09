/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_things.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:45:27 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 17:49:25 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print/print.h"
#include "types.h"

/*
** \file
** \brief
*/

static bool	should_print(const t_flags *flags, t_file *file)
{
	if (file)
	{
		if (!file->is_error)
		{
			if (file->name)
			{
				if (file->name[0] == '.')
				{
					if (!flags->a && !file->no_ignore)
						return (false);
				}
				return (true);
			}
		}
	}
	return (false);
}

void		print_all_things(const t_file *file, const t_flags *flags)
{
	t_file *counter;

	counter = file->files_inside;
	print_directory(counter, flags);
	while (counter)
	{
		if (should_print(flags, counter) && counter->type == Directory)
		{
			ft_printf("%s:\n", counter->full_path);
			print_all_things(counter, flags);
		}
		counter = counter->next;
	}
}
