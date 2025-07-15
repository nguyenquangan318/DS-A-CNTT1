#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc 1 phan tu
typedef struct Node {
    int data;
    struct Node *next;
}Node;

//Xay dung cau truc hang doi
typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

//Xay dung ham khoi tao phan tu
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Xay dung ham khoi tao hang doi
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

//Xay dung ham kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->front == NULL) {
        return 1;
    }
    return 0;
}

//Xay dung ham hien thi hang doi
void display(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    //B2: Khoi tao node tam
    Node *current = queue->front;
    //B3: Su dung node tam de in toan bo hang doi (in toan bo danh sach)
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//Xay dung ham them phan tu vao hang doi
void enQueue(Queue *queue, int data) {
    //B1: Khoi tao phan tu can them
    Node *node = createNode(data);
    //B2: Kiem tra hang doi trong
    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
        return;
    }
    //B3: Them phan tu vao cuoi hang doi (them vao cuoi danh sach)
    queue->rear->next = node;
    queue->rear = node;
}

//Xay dung ham xoa phan tu khoi hang doi
void deQueue(Queue *queue) {
    //B1: Kiem tra hang doi trong
    if (isEmpty(queue)) {
        return;
    }
    //B2: Tien hanh xoa phan tu dau hang doi (Cap nhat con tro front)
    struct Node *currentFront = queue->front;
    //B2.1: Cap nhat con tro front
    queue->front = currentFront->next;
    //B2.2: Xu ly truong hop hang doi chi co 1 phan tu
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    //B3: Giai phong phan tu bi xoa
    free(currentFront);
}

int main(void) {
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    display(queue);
    deQueue(queue);
    display(queue);
    return 0;
}