/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:48:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 20:42:16 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "utils/utils.h"
#include <sys/types.h>

/*
** \file
** \brief Print size
** 			or if it Character_device or Block_device print minor/major
*/

void	print_size(const struct stat *stat_, unsigned size)
{
	if (S_ISCHR(stat_->st_mode) || S_ISBLK(stat_->st_mode))
		ft_printf("%*d, %*d ", size, major(stat_->st_rdev),
				size, minor(stat_->st_rdev));
	else
		ft_printf("%*lld ", size, stat_->st_size);
}
