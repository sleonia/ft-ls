#include "sort/sort.h"
#include "libft.h"
#include <stdio.h>

/*!
** \file
** \brief
*/

/*
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

*/

/* TEST */

static void	swap(t_file *a, t_file *b) {
	t_file *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void sortedInsert(t_file**, t_file*);

void insertionSort(t_file **head_ref) 
{ 
    t_file *sorted = NULL; 
  
    t_file *current = *head_ref; 
    while (current != NULL) 
    { 
        t_file *next = current->next; 
        sortedInsert(&sorted, current); 
        current = next; 
    } 
    *head_ref = sorted; 
} 
  
void sortedInsert(t_file** head_ref, t_file* new_node) 
{ 
    t_file* current;

    if (*head_ref == NULL || (*head_ref)->time < new_node->time)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    //else if (*head_ref == NULL || (*head_ref)->time == new_node->time && ft_strcmp(new_node->name, (*head_ref)->name) > 0) {

	//}
	else
    {
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->time < new_node->time) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
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
	//bubble_sort(false, true, &files);
	//bubble_sort(false, true, &(files->files_inside));
	insertionSort(&files);
	{
		t_file *tmp = files;
		while (tmp)
		{
			printf("%s ", tmp->name);
			tmp = tmp->next;
		}
			printf("\n");
	}
}
