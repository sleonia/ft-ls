/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:41:06 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:41:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

/*
** \file
** \brief
*/

t_file		*reverse(t_file **files)
{
	t_file *current;
	t_file *tail;
	t_file *next;

	if (!files)
		return (NULL);
	current = *files;
	tail = NULL;
	while (current)
	{
		if (current->files_inside)
			current->files_inside = reverse(&(current->files_inside));
		next = current->next;
		current->next = tail;
		tail = current;
		current = next;
	}
	return (tail);
}
