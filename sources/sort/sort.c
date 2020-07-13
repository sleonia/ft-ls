#include "sort/sort.h"

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
	if (a->time <= b->time) {
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
	FrontBackSplit(tmp, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = sorted_merge(a, b);
}

//https://www.geeksforgeeks.org/merge-sort-for-linked-list/

void		sort(const t_flags *flags, t_file **files)
{
	//if () //maybe here need condition by flags
	merge_sort(files);
}