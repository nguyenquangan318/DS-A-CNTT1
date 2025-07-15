#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Xay dung cau truc ngan xep
typedef struct Stack {
    Node *head;
} Stack;

//Xay dung ham khoi tao ngan xep
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

//Xay dung ham them vao ngan xep
int push(Stack *stack, int data) {
    //B1: Khoi tao phan tu can them
    Node *newNode = createNode(data);
    //B2: Kiem tra tran ngan xep
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return 0;
    }
    //B3: Tien hanh them phan tu vao ngan xep (Them vao dau danh sach lien ket)
    newNode->next = stack->head;
    stack->head = newNode;
    //B4: Tra ve gia tri
    return 1;
}

//Xay dung ham lay ra khoi ngan xep
int pop(Stack *stack) {
    //B1: Kiem tra ngan xep trong
    if (stack->head == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    //B2: Lay phan tu tren cung ngan xep (Xoa phan tu dau danh sach)
    Node *currentHead = stack->head;
    int data = currentHead->data;
    stack->head = stack->head->next;
    free(currentHead);
    //B3: Tra ve gia tri lay duoc
    return data;
}

int main(void) {
    return 0;
}