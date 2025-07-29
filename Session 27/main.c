#include <stdio.h>
#include <stdlib.h>

//Xay dung cac cau truc can thiet
typedef struct Operation {
    char url[50];
    char timestamp[50];
} Operation;

typedef struct Stack {
    Operation *operations;
    int capacity;
    int top;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->operations = (Operation *) malloc(sizeof(Operation) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

//Ham khoi tao tien trinh
Operation createOperation() {
    Operation operation;
    printf("Enter url: ");
    fflush(stdin);
    gets(operation.url);
    printf("Enter timestamp: ");
    gets(operation.timestamp);
    return operation;
}

//Ham day tien trinh vao stack
void push(Stack *stack, Operation operation) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->operations[++stack->top] = operation;
}

//Ham kiem tra stack trong
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

//Ham xem phan tu dau stack
void peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Trang web hien tai la: %s\n", stack->operations[stack->top].url);
}

//Ham lay tien trinh ra khoi stack
Operation pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    return stack->operations[stack->top--];
}

int main(void) {
    int choice;
    Stack *backStack = createStack(100);
    Stack *forwardStack = createStack(100);
    do {
        printf("1. VISIT\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Operation operation = createOperation();
                push(backStack, operation);
                break;
            case 2:
                if (isEmpty(backStack)) {
                    printf("Khong co trang web da truy cap");
                    break;
                }
                Operation currentOperation = pop(backStack);
                push(forwardStack, currentOperation);
                break;
            case 3:
                if (isEmpty(forwardStack)) {
                    printf("Khong co trang web da quay lai");
                    break;
                }
                Operation forwardOperation = pop(forwardStack);
                push(backStack, forwardOperation);
                break;
            case 4:
                peek(backStack);
                break;
            case 5:
                printf("Exit program");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}
