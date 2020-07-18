#include "types.h"

#include <stdio.h>

static void	reverse1(t_file **files)
{
	t_file *tmp;
	t_file *prev;
	t_file *next;
//
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
	printf("%p\n", tmp);
}


void	reverse(t_file **files)
{
	t_file *tmp;
	t_file *prev;
	t_file *next;

	printf("%p\n", tmp);

//
	//if (!files || !*files)
	//	return ;
	tmp = *files;
	prev = NULL;
	while (tmp)
	{
		reverse1(&tmp->files_inside);
		next = tmp->next;
		prev = tmp->prev;
		tmp->next = prev;
		tmp->prev = next;
		tmp = next;
	}
	printf("%p\n", tmp);
}
