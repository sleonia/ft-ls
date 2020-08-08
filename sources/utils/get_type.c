/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:31:37 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 15:40:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils/utils.h"

/*
** \file
** \brief Get type of file
** \return	one of "-dcbsl?"
*/

int			get_type(mode_t mode)
{
	mode &= S_IFMT;
	if (mode == S_IFCHR)
		return (Character_device);
	if (mode == S_IFDIR)
		return (Directory);
	if (mode == S_IFBLK)
		return (Block_device);
	if (mode == S_IFREG)
		return (Regular);
	if (mode == S_IFLNK)
		return (Link);
	if (mode == S_IFSOCK)
		return (Socket);
	return (Unknown);
}
