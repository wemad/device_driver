#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev, *next;

}Node;

Node *create_node(int data) {
	Node* new_node = malloc(sizeof(Node));

	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

Node *list_add(Node *head, int data) {
	Node *new_node = create_node(data);

	if (head != NULL) {	
		new_node->next = head;
		head->prev = new_node;
	}

	return new_node;
}

void list_print(Node *head) {

	Node *temp = head;
	if (!head)
		printf("list is empty");

	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

}

Node *list_rev(Node *head) {
	Node *current = head;
	Node *temp;

	while (current) {
		temp = current->prev;  // temp should point to previous node mandatory
		current->prev = current->next;
		current->next = temp;

		current = current->prev;
	}

	head = temp->prev;  // temp point to 2nd node
	return head;
}


void main()
{
	Node* head = NULL;
	head = list_add(head, 12);
	head = list_add(head, 13);
	head = list_add(head, 15);
	head = list_add(head, 16);
	list_print(head);
	head = list_rev(head);
	list_print(head);

}
