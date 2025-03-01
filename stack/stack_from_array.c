
#include <stdio.h>

#define SIZE 10

struct stack {
	int arr[SIZE];
	int top;
};

void push(struct stack *var, int data) {
	if (var->top >= SIZE - 1) {
		printf("stack is full\n");
		return;
	}

	var->top++;
	var->arr[var->top] = data;
	printf("pushed:%d\n", var->arr[var->top]);
}

void pop(struct stack *var) {
	if (var->top <= 0) {
		printf("stack is empty");
		return;
	}
	printf("poped %d\n", var->arr[var->top]);
	var->top--;
}

void print_stack(struct stack *var) {
	int i;
	for(i = 0; i <= var->top; i++) {
		printf("%d\n", var->arr[i]);
	}
}

void main() {
	struct stack var;
	var.top = -1;
	push(&var, 10);
	push(&var, 20);
	push(&var, 30);
	push(&var, 40);
	push(&var, 50);
	push(&var, 60);
	push(&var, 70);
	push(&var, 80);
	push(&var, 90);
	push(&var, 100);
	push(&var, 100);
	push(&var, 200);
	pop(&var);
	pop(&var);
	print_stack(&var);
}
