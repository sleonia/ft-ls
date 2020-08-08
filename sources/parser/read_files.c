/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:05:20 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 19:05:21 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "utils/utils.h"
#include "print/print.h"
#include "ft_printf.h"

/*
** \file
** \brief
*/

void			read_files(int index, t_file *files, const char **args,
		t_flags *flags)
{
	t_file	*tmp;
	t_file	*prev;

	tmp = files;
	if (!args[index])
	{
		files->no_ignore = true;
		fill_file("./", files, flags);
	}
	else
	{
		if (flags->no_flags)
			index = 0;
		while (args[++index])
		{
			tmp->no_ignore = true;
			tmp->full_path = build_path_for_arg(args[index]);
			fill_file(args[index], tmp, flags);
			prev = tmp;
			tmp = new_file(tmp);
		}
		if (!tmp->name)
			del_last(prev, tmp);
	}
}
