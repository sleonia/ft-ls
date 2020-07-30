#include "types.h"

t_file 		*reverse(t_file **files)
{
	t_file *current;
	t_file *tail;
	t_file *next;

	if (!files)
		return NULL;
	current = *files;
	tail = NULL;
	while (current)
	{
		if (current->files_inside)
			current->files_inside = reverse(&(current->files_inside));
		next = current->next;
		current->next = tail;
		tail = current;
		current = next;
	}
	return (tail);
}
