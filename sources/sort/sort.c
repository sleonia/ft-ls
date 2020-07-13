#include "sort/sort.h"
#include <stdio.h>

void front_back_split(t_file* head, t_file** a, t_file** b) {
	t_file* slow = head;
	t_file* fast = head->next;
	while (fast) {
		fast = fast->next;
		if (fast) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

t_file*	sorted_merge(t_file* a, t_file* b) {
	t_file* res = NULL;
	if (!a) { return b;}
	if (!b) { return a;}
	if (a->time >= b->time) {
		res = a;
		res->next = sorted_merge(a->next, b);
	} else {
		res = b;
		res->next = sorted_merge(a, b->next);
	}
	return res;
}

void	merge_sort(t_file** head) {
	t_file* tmp = *head;
	t_file* a;
	t_file* b;

	if (!tmp || !tmp->next) {
		return ;
	}
	front_back_split(tmp, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*head = sorted_merge(a, b);
}

//https://www.geeksforgeeks.org/merge-sort-for-linked-list/

void		sort(const t_flags *flags, t_file **files)
{
	//if () //maybe here need condition by flags
	//printf("* %p, ** %p, next %p\n", files, &files, (*files)->next);
	//merge_sort(files);
	merge_sort(&(*files)->files_inside);
}