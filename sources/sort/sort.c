#include "sort/sort.h"
#include "libft.h"
#include <stdio.h>

/*!
** \file
** \brief
*/

static void	front_back_split(t_file *head, t_file **left, t_file **right)
{
	t_file *slow;
	t_file *fast;

	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = head;
	*right = slow->next;
	slow->next = NULL;
}

static t_file	*sorted_merge_by_time(t_file *left, t_file *right)
{
	t_file *res;

	res = NULL;
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (left->time > right->time)
	{
		res = left;
		res->next = sorted_merge_by_time(left->next, right);
	}
	else if (left->time == right->time && ft_strcmp(right->name, left->name) > 0)
	{
		res = left;
		res->next = sorted_merge_by_time(left->next, right);
	}
	else
	{
		res = right;
		res->next = sorted_merge_by_time(left, right->next);
	}
	return (res);
}

static t_file	*sorted_merge_by_ascii(t_file *left, t_file *right)
{
	t_file *res;

	res = NULL;
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (left->name && right->name && ft_strcmp(right->name, left->name) > 0)
	{
		res = left;
		res->next = sorted_merge_by_ascii(left->next, right);
	}
	else
	{
		res = right;
		res->next = sorted_merge_by_ascii(left, right->next);
	}
	return (res);
}

void	merge_sort(bool is_ascii, bool is_time, t_file **head)
{
	t_file *tmp;
	t_file *left;
	t_file *right;

	tmp = *head;
	left = NULL;
	right = NULL;
	if (!tmp || !tmp->next)
		return ;
	front_back_split(tmp, &left, &right);
	merge_sort(is_ascii, is_time, &left);
	merge_sort(is_ascii, is_time, &right);
	if (is_ascii)
		*head = sorted_merge_by_ascii(left, right);
	else
		*head = sorted_merge_by_time(left, right);
}


static void	swap(t_file *a, t_file *b) {
	t_file *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void		bubble_sort(bool is_ascii, bool is_time, t_file **head) { //only for test
	t_file *i;
	t_file *k;

	if (!head || !*head)
		return ;
	i = *head;
	while (i) {
		k = i;
		while (k && k->next && k->next->next) {
			if (i->time > k->time) {
				swap(i, k);
			} else if (i->time == k->time && ft_strcmp(k->name, i->name) > 0) {
				swap(i, k);
			} else {
				swap(k, i);
			}
			k = k->next;
		}
		i = i->next;
	}
}


void		sort(const t_flags *flags, t_file *files)
{
		/*
	if (flags->t)
	{
		merge_sort(false, flags->t, &(files));
		merge_sort(false, flags->t, &(files->files_inside));
	}

	else
	{
		if (!flags->f)
		{
			merge_sort(true, false, &(files));
			merge_sort(true, false, &(files->files_inside));
		}

		if (flags->little_r)
			reverse(&files);
	}
	*/
	bubble_sort(true, false, &files);
	bubble_sort(true, false, &(files->files_inside));
	//{
		//t_file *tmp = files->files_inside;
		//while (tmp)
		//{
			//printf("prev: %s ", tmp->prev == NULL ? "" :  tmp->prev->name);
			//printf("\t\t\tcurr: %s ", tmp->name);
			//printf("\n");
			//tmp = tmp->next;
		//}
	//}
}
