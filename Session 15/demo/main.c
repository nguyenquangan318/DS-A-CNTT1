#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc du lieu hang doi su dung mang
typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

//Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    //B1: Cap phat bo nho cho hang doi
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    //B2: Gan cac gia tri can thiet
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    //B3: Tra ve dia chi hang doi duoc khoi tao
    return queue;
}

//Xay dung ham them phan tu vao hang doi
void enQueue(Queue *queue, int value) {
    //B1: Kiem tra hang doi day
    if (queue->rear < queue->capacity - 1) {
        //B2: Tang chi so phan tu cuoi hang doi
        queue->rear++;
        //B3: Gan gia tri cho phan tu cuoi hang doi
        queue->arr[queue->rear] = value;
    }
}

//xay dung ham kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

//Xay dung ham xoa phan tu ra dau hang doi
void deQueue(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (!isEmpty(queue)) {
        //B2: Tang chi so cua phan tu dau tien
        queue->front++;
    }

}

//Xay dung ham xem phan tu dau hang doi
int getFront(Queue *queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    return queue->arr[queue->front];
}

//Xay dung ham hien thi toan bo hang doi
void displayQueue(Queue *queue) {
    if (!isEmpty(queue)) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
    }
}

int main(void) {
    Queue *queue = createQueue(10);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    // printf("%d\n", getFront(queue));
    deQueue(queue);
    deQueue(queue);
    enQueue(queue, 4);
    displayQueue(queue);
    return 0;
}