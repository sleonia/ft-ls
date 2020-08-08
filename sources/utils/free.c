/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:31:53 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:33:13 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils.h"
#include "libft.h"

/*
** \file
** \brief
*/

static void	free_file(t_file *file)
{
	if (!file)
		return ;
	if (file->files_inside)
		free_file(file->files_inside);
	if (file->next)
		free_file(file->next);
	ft_strdel(&file->name);
	ft_strdel(&file->full_path);
	if (file->fd)
		closedir(file->fd);
	ft_memdel((void **)&file->conf);
	ft_memdel((void **)&file);
}

int			free_all(t_file *files, t_flags *flags)
{
	if (flags)
		free(flags);
	free_file(files);
	return (0);
}
