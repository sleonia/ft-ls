/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:34:21 by sleonia           #+#    #+#             */
/*   Updated: 2020/08/08 19:59:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

/*
** \file
** \brief Create full path
**		Example of path:
**			-	"~"
**			-	"/"
**			-	"/Users/sleonia/Desktop"
*/

char	*build_path(t_file *file)
{
	char	*buf;
	char	*result;
	t_file	*file_counter;

	result = ft_strdup(file->name);
	buf = NULL;
	file_counter = file;
	if (file->origin)
	{
		if (result[0] != '/' && !ft_strequ(file->origin->full_path, "./"))
			buf = ft_strjoin("/", result);
		else if (ft_strequ(file->origin->full_path, "./"))
			buf = ft_strjoin("./", result);
		else
			buf = ft_strdup(result);
		ft_strdel(&result);
		if (!ft_strequ(file_counter->origin->full_path, "/") &&
			!ft_strequ(file->origin->full_path, "./"))
			result = ft_strjoin(file_counter->origin->full_path, buf);
		else
			result = ft_strdup(buf);
		ft_strdel(&buf);
		file_counter = file_counter->origin;
	}
	return (result);
}

char	*build_path_for_arg(const char *name)
{
	char *buf;

	if (name[0] == '/')
		return (ft_strdup(name));
	if (ft_strcmp("./", name) == 0)
		buf = ft_strdup(name);
	else
	{
		buf = ft_strstr(name, "User");
		if (!buf && name[0] != '.')
			buf = ft_strjoin("./", name);
		else
			buf = ft_strdup(name);
	}
	return (buf);
}
