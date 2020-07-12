#include <iostream>

using namespace std;

struct List {
	List() {}
	List(int a) : a_(a) {}
	List(int a, List* next) : a_(a), next_(next) {}
	int a_;
	struct List* next_;
};

void	Print(List* head) {
	List* tmp = head;
	while (tmp) {
		cout << tmp->a_ << ' ';
		tmp = tmp->next_;
	}
	cout << "\n";
}

void FrontBackSplit(List* head, List** a, List** b) {
	List* slow = head;
	List* fast = head->next_;
	while (fast) {
		fast = fast->next_;
		if (fast) {
			slow = slow->next_;
			fast = fast->next_;
		}
	}
	slow->next_ = nullptr;
}

List*	SortedMerge(List* a, List* b) {
	List* res = nullptr;
	if (!a) { res = b; return res;}
	if (!b) { res = a; return res;}
	if (a->a_ <= b->a_) {
		res->a_ = a->a_;
		res->next_ = SortedMerge(a->next_, b);
	} else {
		res->a_ = b->a_;
		res->next_ = SortedMerge(a, b->next_);
	}
	return res;
}

void	MergeSort(List** head) {
	List* tmp;
	List* a;
	List* b;

	if (!head || !*head) {
		return ;
	}
	tmp = *head;
	FrontBackSplit(tmp, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = SortedMerge(a, b);
}

void push(List** head_ref, int new_data) 
{ 
    List* new_node = new List(); 
    new_node->a_ = new_data; 
    new_node->next_ = (*head_ref); 
    (*head_ref) = new_node; 
} 

int main() 
{ 
    List* res = nullptr; 
    List* head = nullptr; 
  
    push(&head, 15); 
    push(&head, 10); 
    push(&head, 5); 
    push(&head, 20); 
    push(&head, 3); 
    push(&head, 2); 
  
	Print(head);
    MergeSort(&head); 
	Print(head);
    return 0; 
} 