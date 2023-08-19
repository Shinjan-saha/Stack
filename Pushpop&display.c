#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int is_empty(struct Stack *stack) {
    return stack->top == -1;
}

int is_full(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack *stack, int item) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d pushed onto the stack.\n", item);
}

int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

void display(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, item;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choices : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
