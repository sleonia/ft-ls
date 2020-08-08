/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:43:16 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:43:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** \file
** Example of link:
**		Network -> /System/Volumes/Data/Network
*/

void	print_link_value(const char *full_path)
{
	int		size;
	char	buf[PATH_MAX];

	size = readlink(full_path, buf, PATH_MAX);
	buf[size] = '\0';
	ft_printf(" -> %s", buf);
}
