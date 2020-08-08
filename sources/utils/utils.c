/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:33:18 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:33:56 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

/*
** \file
** \brief Some funcs for memory management
*/

t_flags		*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)ft_memalloc(sizeof(t_flags));
	return (flags);
}

t_file		*init_file(void)
{
	t_file	*files;

	files = (t_file*)ft_memalloc(sizeof(t_file));
	return (files);
}

t_file		*new_file(t_file *prev)
{
	t_file	*file;

	file = init_file();
	if (prev)
		prev->next = file;
	return (file);
}

t_conf		*new_conf(void)
{
	t_conf	*conf;

	conf = (t_conf*)ft_memalloc(sizeof(t_conf));
	return (conf);
}
