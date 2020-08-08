/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:03:59 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 19:04:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "ft_printf.h"

/*
** \file
** \brief
*/

void			del_last(t_file *prev, t_file *curr)
{
	prev->next = NULL;
	ft_memdel((void **)&curr);
}
