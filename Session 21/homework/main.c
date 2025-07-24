#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cau truc cua 1 node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

//B2: Xay dung ham khoi tao node
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Xay dung cau truc hang doi
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;

//Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue *) malloc(sizeof(Queue));
    newQueue->arr = (Node **) malloc(sizeof(Node *) * capacity);
    newQueue->capacity = capacity;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

//Xay dung phuong thuc them vao hang doi
void enqueue(Queue *queue, Node *node) {
    //Kiem tra hang doi day
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    //Day phan tu vao hang doi
    queue->arr[++queue->rear] = node;
}

//Xay dung phuong thuc kiem tra hang doi trong
int isEmpty(Queue *queue) {
    if (queue->rear < queue->front) {
        return 1;
    }
    return 0;
}

//Xay dung phuong thuc lay ra khoi hang doi
Node *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}

Node *deleteFromTree(Node *root, int data) {
    //Tim cac node can thiet: target, lastNode, lastParent
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    //Thuc hien BFS
    //B1: Khoi tao hang doi va dua root vao hang doi
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    //B2: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //Kiem tra node duoc xet co phai node can xoa khong va luu lai
        Node *node = dequeue(queue);
        if (node->data == data) {
            target = node;
        }
        // Kiem tra con cua node duoc xet va day vao hang doi neu co
        // Cap nhat lastNode va lastParent
        if (node->left != NULL) {
            enqueue(queue, node->left);
            lastNode = node->left;
            lastParent = node;
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
            lastNode = node->right;
            lastParent = node;
        }
    }
    //Tien hanh xoa
    //B1: Ghi de du lieu cua target
    target->data = lastNode->data;
    //B2: Xoa lastNode khoi cay (Cap nhat con ben trai hoac phai cua lastParent)
    if (lastParent->left == lastNode) {
        lastParent->left = NULL;
    }else {
        lastParent->right = NULL;
    }
    //B3: Giai phong lastNode
    free(lastNode);
}
int main(void) {
    return 0;
}