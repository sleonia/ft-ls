#include "types.h"

#include <stdio.h>

static void	reverse1(t_file **files)
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
		//printf("%s\n", tmp->name);
		next = (*tmp)->next;
		prev = (*tmp)->prev;
		(*tmp)->next = prev;
		(*tmp)->prev = next;
		if (!next)
		{
			//printf("%s\n", (*files)->name);
			//printf("%s\n", (*files)->next->name);
			break ;
		}
		(*tmp) = next;
	}
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
		reverse1(&(*tmp)->files_inside);
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
