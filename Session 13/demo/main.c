#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc du lieu ngan xep
typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;

//Xay dung ham khoi tao ngan xep
Stack *createStack(int cap) {
    //B1: Cap phat bo nho cho ngan xep can khoi tao
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    //B2: Gan gia tri cho top (chi so phan tu tren cung stack)
    stack->top = -1;
    //B3: Gan gia tri cho cap (kich thuoc cua stack)
    stack->cap = cap;
    //B3: Cap phat bo nho cho mang va gan gia tri cho arr
    stack->arr = (int *) malloc(sizeof(int) * cap);
    //B4: Tra ve stack da duoc khoi tao
    return stack;
}

//Xay dung ham kiem tra stack overflow
int isFull(Stack *stack) {
    //So sanh top va cap va tra ve ket qua
    if (stack->top == stack->cap - 1) {
        return 1;
    }
    return 0;
}

//Xay dung ham them phan tu vao stack
int push(Stack *stack, int val) {
    //B1: Kiem tra stack overflow va tra ve gia tri
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return 0;
    }
    //B2: Tien hanh day phan tu vao ngan xep
    //B2.1: Cap nhat gia tri top
    // stack->top = stack->top + 1;
    //B2.2: Day gia tri vao tren cung ngan xep
    // stack->arr[stack->top] = val;
    stack->arr[++stack->top] = val;
    //B3: Tra ve gia tri
    return 1;
}

//Xay dung ham kiem tra ngan xep trong
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

//Xay dung ham lay phan tu ra khoi ngan xep
int pop(Stack *stack) {
    //B1: Kiem tra ngan xep trong va tra ve ket qua
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return 0;
    }
    //B2: Giam gia tri top di 1
    // stack->top = stack->top - 1;
    //B3: Tra ve gia tri duoc lay ra
    // return stack->arr[stack->top + 1];
    return stack->arr[stack->top--];
}

int main(void) {
    Stack *stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    // push(stack, 4);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    return 0;
}
