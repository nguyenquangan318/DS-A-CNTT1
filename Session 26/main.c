#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[50];

typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation *operations;
    int capacity;
    int top;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->operations = (Operation *) malloc(stack->capacity * sizeof(Operation));
    return stack;
}

Operation createOperation(char action, char character) {
    Operation operation;
    operation.action = action;
    operation.value = character;
    return operation;
}

void push(Stack *stack, Operation operation) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->operations[++stack->top] = operation;
}

void insertToString(char character) {
    int length = strlen(string);
    string[length] = character;
    string[length + 1] = '\0';
}

void deleteFromString() {
    int length = strlen(string);
    string[length - 1] = '\0';
}

int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

Operation pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    return stack->operations[stack->top--];
}

int main(void) {
    int choice;
    Operation operation;
    Stack *undoStack = createStack(100);
    Stack *redoStack = createStack(100);
    do {
        printf("1. INSERT\n ");
        printf("2. UNDO\n ");
        printf("3. REDO\n ");
        printf("4. SHOW\n ");
        printf("5. EXIT\n ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                char character;
                printf("Nhap vao ky tu muon them: ");
                fflush(stdin);
                scanf("%c", &character);
                insertToString(character);
                operation = createOperation('I', character);
                push(undoStack, operation);
                break;
            case 2:
                if (isEmpty(undoStack)) {
                    printf("Undo stack is empty\n");
                    break;
                }
                operation = pop(undoStack);
                deleteFromString();
                push(redoStack, operation);
                break;
            case 3:
                if (isEmpty(redoStack)) {
                    printf("Redo stack is empty\n");
                    break;
                }
                operation = pop(redoStack);
                insertToString(operation.value);
                push(undoStack, operation);
                break;
            case 4:
                printf("Chuoi hien tai la: ");
                puts(string);
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 5);
    return 0;
}
