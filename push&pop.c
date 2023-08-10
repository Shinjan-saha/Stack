#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent the stack
typedef struct {
    int data[MAX_SIZE];
    int top; // Index of the top element in the stack
} Stack;

// Function to initialize a stack
void initStack(Stack *stack) {
    stack->top = -1; // Initialize top to -1 to indicate an empty stack
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return a special value to indicate underflow
    }
    
    int poppedValue = stack->data[stack->top];
    stack->top--;
    return poppedValue;
}

int main() {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack)); // Trying to pop from an empty stack
    
    return 0;
}

