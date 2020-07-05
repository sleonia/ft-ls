#include "utils/utils.h"
#include "libft.h"

t_flags		*init_flags(void)
{
	t_flags	*flags;

	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	return (flags);
}

t_folder		*init_folder(void)
{
	t_folder	*folders;

	if (!(folders = (t_folder*)ft_memalloc(sizeof(t_folder))))
		return (NULL);
	return (folders);
}