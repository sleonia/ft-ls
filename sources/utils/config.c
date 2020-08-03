#include "utils/utils.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>

int	nbrlen(long long nbr)
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

/*!
**	\brief Take config (size) for output:
**		- conf->total
**		- conf->links_len
**		- conf->creator_len
**		- conf->group_len
**		- conf->size_len
**		- conf->name_len
**		- conf->inode_nbr_len
*/

void		take_config(const char *name, const struct stat *stat_, const t_flags *flags, t_conf *conf)
{
	int		len;

	if (flags->a)
		++conf->count;
	else if (name[0] != '.')
		++conf->count;
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
	if (flags->a)
		conf->name_len < len ? conf->name_len = len : 0;
	else if (name[0] != '.')
		conf->name_len < len ? conf->name_len = len : 0;
	len = nbrlen(stat_->st_ino);
	conf->inode_nbr_len < len ? conf->inode_nbr_len = len : 0;
}