#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cac cau truc can thiet
typedef struct Call {
    char phone[10];
    int time;
} Call;
typedef struct Stack {
    Call *calls;
    int top;
    int capacity;
} Stack;
typedef struct Queue {
    Call *calls;
    int front;
    int rear;
    int capacity;
} Queue;

//B2: Xay dung ham khoi tao cac cau truc du lieu
Stack *createStack(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

//B3: Lan luot xay dung cac phuong thuc de giai quyet cac yeu cau
    //B3.1: Xay dung ham day vao hang doi va ngan xep
    //B3.2: Xay dung ham xoa khoi ngan xep
    //B3.3: Xay dung ham hien thi toan bo hang doi
void push(Stack *stack, Call call) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->calls[stack->top] = call;
}
Call pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return ;
    }
    stack->top--;
    return stack->calls[stack->top];
}
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
void enqueue(Queue *queue, Call call) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->calls[queue->rear] = call;
}
void displayQueue(Queue *queue) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i <= queue->rear; i++) {
        printf("%s ", queue->calls[i].phone);
        printf("%d ", queue->calls[i].time);
    }
}
int main(void) {
    int choice;
    Stack *backStack = createStack(10);
    Stack *forwardStack = createStack(10);
    Queue *queue = createQueue(10);
    do {
        printf("1. CALL\n");
        printf("2. BACK\n");
        printf("3. REDIAL\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Call call;
                printf("Enter the phone number: ");
                scanf("%s", call.phone);
                printf("Enter the time of the call: ");
                scanf("%d", &call.time);
                push(backStack, call);
                enqueue(queue, call);
                forwardStack = createStack(10);
                break;
            case 2:
                if (isEmpty(backStack)) {
                    printf("Khong co cuoc goi nao da duoc goi\n");
                    break;
                }
                Call backCall = pop(backStack);
                printf("Phone number: %s\n", backCall.phone);
                printf("Time of the call: %d\n", backCall.time);
                push(forwardStack, backCall);
                break;
            case 3:
                if (isEmpty(forwardStack)) {
                    printf("Khong co cuoc goi nao da duoc quay lai\n");
                }
                Call forwardCall = pop(forwardStack);
                printf("Phone number: %s\n", forwardCall.phone);
                printf("Time of the call: %d\n", forwardCall.time);
                push(backStack, forwardCall);
                enqueue(queue, forwardCall);
                break;
            case 4:
                displayQueue(queue);
                break;
            case 5:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}
