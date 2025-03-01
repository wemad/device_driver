#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *list_middle(struct Node *head) {
	struct Node *slow = head;
	struct Node *fast = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;	
	}

	return slow;
}

struct Node *create_node(int data) {
	struct Node *tmp  = malloc(sizeof(struct Node));
	
	if (!tmp)
		return tmp;

	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void list_print(struct Node *head) {
	struct Node *temp = head;
	
	if (head == NULL)
		printf("list is empty\n");

	while(temp) {   // 1 2 3 4
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void list_del(struct Node **head) {
	struct Node *temp, *temp1 = *head;

	while (temp1) {
		temp = temp1;
		temp1 = temp1->next;
		free(temp);	
	}
	*head = NULL;
}

#if 0
struct Node *my_list_rev_r(struct Node *prev, struct Node *curr, struct Node *next) {

	if (curr == NULL) {
		return prev;
	}
	
	next = curr->next;
	curr->next = prev;
	prev = curr; 
	curr  = next;

	return list_rev_r(prev, curr, next);
}
#endif

bool listcycle(struct Node *head) {
	struct Node *slow = head;
	struct Node *fast = head;
	
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}

	return false;
}

struct Node *list_hascycle(struct Node *head) {
	struct Node* slow = head;
	struct Node* fast = head;
	struct Node* prev = NULL;


	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (!fast || !fast->next) 
		return NULL;

	slow = head;
	while (slow != fast) {
		prev = fast;
		slow = slow->next;
		fast = fast->next;
	}

	if (prev)
		prev->next = NULL;	
	return slow;
}

struct Node *list_rev_r(struct Node *head){

	if (head == NULL || head->next == NULL)
		return head;

	struct Node *new_head = list_rev_r(head->next);

	head->next->next = head;
	head->next = NULL;

	return new_head;
}

void list_rev(struct Node **head) {

	struct Node* next, *prev = NULL;
	struct Node* curr = *head;

	while(curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr; 
		curr  = next;
	}
	*head = prev;
}

#if 0
struct Node* list_add(struct Node* head, int data) {

	struct Node *temp = create_node(data);
	
	if (!temp) {
		printf("failed to allocate new node\n");
		return head;
	}
		
	temp->next = head;

	return temp;
}
#endif

void list_add(struct Node **head, int data) 
{
	struct Node *new_node = create_node(data);

	new_node->next = *head;

	*head = new_node;
}

void main() {
	
	struct Node *head = NULL;
	list_add(&head, 12);
	list_add(&head, 13);
	list_add(&head, 15);
	list_print(head);

//	head = list_rev_r(head);
//	list_del(&head);
//	list_print(head);
}
