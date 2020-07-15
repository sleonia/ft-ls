#include "utils/utils.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

/*!
* \file
* \brief
*/

t_flags		*init_flags(void)
{
	t_flags	*flags;

	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	return (flags);
}

t_file 		*init_file(void)
{
	t_file 	*files;

	if (!(files = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	return (files);
}

t_file			*new_file(t_file *prev)//this didnt work with void because of a copy of pointer being sent as arg inside of the actual pointer thus the resulted *file leaked while staying NULL
{
	t_file 	*file;

	if (!(file = init_file()))
		return (NULL);
	if (prev)
	{
		prev->next = file;
		file->prev = prev;
	}
	return (file);
}

t_conf			*new_conf(void)
{
	t_conf		*conf;

	if (!(conf = (t_conf*)ft_memalloc(sizeof(t_conf))))
		return (NULL);
	return (conf);
}

char *build_path(t_file *file)//////this shit will break on a file with no name, this is intended, don't fix it
{
	char *buf;
	char *result;
	t_file *file_counter;


	result = ft_strdup(file->name);////protect me
	file_counter = file;
	if (file->origin)
	{
		while (file_counter->origin)
		{
			buf = ft_strjoin("/", result);/////protect me but first check if it's needed
			ft_strdel(&result);
			result = ft_strjoin(file_counter->origin->name, buf);/////protect me
			ft_strdel(&buf);
			file_counter = file_counter->origin;
		}
	}
	return (result);
}

char *build_path_for_arg(const char *name)
{
	char *result;

	result = ft_strjoin("./", name);///protect me
	return (result);
}

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

void		take_config(const char *name, const struct stat *stat_, t_conf *conf)
{
	int		len;

	conf->total += stat_->st_blocks;
	len = nbrlen(stat_->st_nlink);
	conf->links_len < len ? conf->links_len = len : 0;
	len = ft_strlen((getpwuid(stat_->st_uid))->pw_name);
	conf->creator_len < len ? conf->creator_len = len : 0;
	len = ft_strlen(getgrgid(stat_->st_gid)->gr_name);
	conf->group_len < len ? conf->group_len = len : 0;
	len = nbrlen(stat_->st_size);
	conf->size_len < len ? conf->size_len = len : 0;
	len = ft_strlen(name);
	conf->name_len < len ? conf->name_len = len : 0;
}