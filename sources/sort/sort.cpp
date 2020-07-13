#include <iostream>

using namespace std;

struct List {
	List() {}
	List(int a) : field_(a) {}
	List(int a, List* next) : field_(a), next_(next) {}
	int field_;
	struct List* next_;
};

void	Print(List* head) {
	List* tmp = head;
	while (tmp) {
		cout << tmp->field_ << ' ';
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
	*a = head;
	*b = slow->next_;
	slow->next_ = nullptr;
}

List*	SortedMerge(List* a, List* b) {
	List* res = nullptr;
	if (!a) { return b;}
	if (!b) { return a;}
	if (a->field_ <= b->field_) {
		res = a;
		res->next_ = SortedMerge(a->next_, b);
	} else {
		res = b;
		res->next_ = SortedMerge(a, b->next_);
	}
	return res;
}

void	MergeSort(List** head) {
	List* tmp = *head;
	List* a;
	List* b;

	if (!tmp || !tmp->next_) {
		return ;
	}
	FrontBackSplit(tmp, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*head = SortedMerge(a, b);
}

void push(List** head_ref, int new_data) 
{ 
    List* new_node = new List(); 
    new_node->field_ = new_data; 
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