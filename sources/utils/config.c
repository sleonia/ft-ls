/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:34:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/09 19:49:50 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "libft/libft.h"
#include <pwd.h>
#include <grp.h>

int			nbrlen(long long nbr)
{
	int		i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

/*
**	\brief Take config (size) for output:
**		- conf->total
**		- conf->links_len
**		- conf->creator_len
**		- conf->group_len
**		- conf->size_len
**		- conf->name_len
**		- conf->inode_nbr_len
*/

void		take_config(const char *name, const struct stat *stat_,
					const t_flags *flags, t_conf *conf)
{
	unsigned	len;

	len = name != NULL ? ft_strlen(name) : 0;
	if (flags->a || (!flags->a && name[0] != '.'))
	{
		++conf->count_actual;
		conf->total += stat_->st_blocks;
		conf->name_len < len ? conf->name_len = len : 0;
	}
	++conf->count_total;
	len = nbrlen(stat_->st_nlink);
	conf->links_len < len ? conf->links_len = len : 0;
	len = ft_strlen((getpwuid(stat_->st_uid))->pw_name);
	conf->creator_len < len ? conf->creator_len = len : 0;
	len = ft_strlen(getgrgid(stat_->st_gid)->gr_name);
	conf->group_len < len ? conf->group_len = len : 0;
	len = nbrlen(stat_->st_size);
	conf->size_len < len ? conf->size_len = len : 0;
}
