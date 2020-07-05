#include "utils/utils.h"
#include "libft.h"

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

void			new_file(t_file *prev)
{
	t_file 	*file;

	file = init_file();
	if (prev)
		prev->next = file;
}
