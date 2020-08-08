/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:42:36 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:42:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "print/print.h"
#include "sort/sort.h"

/*
** \file
** \brief Main file.
** \details How if works:
**		1. Init structs
**		2. Parsing input agruments by flags
**		3. Parsing input agruments by folders
**			calculate sizes for output
**		4. Sort
**		5. Print result
*/

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file		*files;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (free_all(NULL, flags));
	if (!parser((const char **)av, files, flags, ac))
		return (free_all(files, flags));
	sort((const t_flags*)flags, &files);
	print((const t_flags*)flags, (const t_file*)files);
	free_all(files, flags);
	return (0);
}
