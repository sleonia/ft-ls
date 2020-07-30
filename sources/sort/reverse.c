#include "types.h"

#include <stdio.h>

void	reverse(t_file **files)
{
	t_file *current;
	t_file *prev;
	t_file *next;

	if (!files || !*files)
		return ;
	current = *files;
	prev = NULL;
	while (current)
	{
		if ((*files)->files_inside)
			reverse(&(*files)->files_inside);
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*files = prev;
}
