#include <stdio.h>
#include <stdlib.h>

// typedef struct Node {
//     int data;
// }Node;
//B1: Xay dung cau truc hang doi
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
//Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int *)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
//B2: Xay dung cac phuong thuc voi hang doi
//B2.1: Phuong thuc them vao hang doi
void enQueue(Queue *queue, int data) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->arr[++queue->rear] = data;
}
//B2.2: Phuong thuc kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
