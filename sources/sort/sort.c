#include "sort/sort.h"
#include "libft.h"
#include <stdio.h>

/*!
* \file
* \brief
*/

static void front_back_split(t_file* head, t_file** a, t_file** b)
{
	t_file* slow;
	t_file* fast;

	slow = head;
	fast = fast->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

static t_file*	sorted_merge_by_time(t_file* a, t_file* b)
{
	t_file* res;

	res = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->time >= b->time)
	{
		res = a;
		res->next = sorted_merge_by_time(a->next, b);
	}
	else
	{
		res = b;
		res->next = sorted_merge_by_time(a, b->next);
	}
	return res;
}

static t_file*	sorted_merge_by_ascii(t_file* a, t_file* b)
{
	t_file* res;

	res = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a->name && b->name && strcmp(a->name, b->name) > 0)
	{
		res = a;
		res->next = sorted_merge_by_ascii(a->next, b);
	}
	else
	{
		res = b;
		res->next = sorted_merge_by_ascii(a, b->next);
	}
	return res;
}

void	merge_sort(const bool is_ascii, const bool is_time, t_file** head)
{
	t_file* tmp;
	t_file* a;
	t_file* b;

	tmp = *head;
	if (!tmp || !tmp->next) {
		return ;
	}
	front_back_split(tmp, &a, &b);
	merge_sort(is_ascii, is_time, &a);
	merge_sort(is_ascii, is_time, &b);
	if (is_ascii)
		*head = sorted_merge_by_ascii(a, b);
	else
		*head = sorted_merge_by_time(a, b);
}

/*!
* https://www.geeksforgeeks.org/merge-sort-for-linked-list/
*/

void		sort(const t_flags *flags, t_file *files)
{
	merge_sort(flags->little_r, flags->t, &(files->files_inside));
}