/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:28:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 14:28:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "types.h"

/*
** \file
** \brief Reverse and sort folders and files
**	Merge sort:
**	- by ascii
**	- by time
*/

void		sort(const t_flags *flags, t_file **files);
t_file		*reverse(t_file **files);

#endif
