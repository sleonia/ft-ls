#include "types.h"

#include <stdio.h>

static void	reverse1(t_file **files)
{
	t_file *tmp;
	t_file *prev;
	t_file *next;

	if (!files || !*files)
		return ;
	tmp = *files;
	prev = NULL;
	while (tmp)
	{
		next = tmp->next;
		prev = tmp->prev;
		tmp->next = prev;
		tmp->prev = next;
		tmp = next;
	}
	*files = next;
}

void	reverse(t_file **files)
{
	t_file **tmp;
	t_file *prev;
	t_file *next;
//
	if (!files || !*files)
		return ;
	tmp = files;
	prev = NULL;
	while (tmp)
	{
		reverse1(&(*tmp)->files_inside); //null?
		next = (*tmp)->next;
		prev = (*tmp)->prev;
		(*tmp)->next = prev;
		(*tmp)->prev = next;
		if (!next)
		{
			break ;
		}
		(*tmp) = next;
	}
}
