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

//Xay dung ham them moi vao cay
Node *insert(Queue *root, int data) {
    //Khoi tao node can them
    Node *newNode = createNode(data);
    //B1: Kiem tra cay khong co node nao
    if (isEmpty(root)) {
        return newNode;
    }
    //B2: Khoi tao hang doi va dua node goc vao hang doi
    Queue *queue = createQueue(100);
    enqueue(root, newNode);
    //B3: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(root)) {
        //B4: Lay node dau hang doi ra
        Node *node = dequeue(root);
        //B5: Kiem tra con cua node duoc lay ra
        if (node->left != NULL) {
            //B6: Neu co node con thi day node con vao hang doi
            enqueue(queue, node->left);
        } else {
            //B7: Neu khong co node con thi chen node can them vao
            node->left = newNode;
        }
        if (node->right != NULL) {
            //B6: Neu co node con thi day node con vao hang doi
            enqueue(queue, node->right);
        } else {
            //B7: Neu khong co node con thi chen node can them vao
            node->right = newNode;
        }
    }
}

//Xay dung ham xoa khoi hang doi
Node *delete(Node *root, int data) {
    //B1: Kiem tra cay khong co node nao
    if (root == NULL) {
        return NULL;
    }
    //B2: Khoi tao hang doi va dua root vao hang doi
    Queue *queue = createQueue(100);
    enqueue(queue, root);
    //B3: Khoi tao 3 bien target, lastNode, lastParent
    Node *target = NULL;
    Node *lastNode = NULL;
    Node *lastParent = NULL;
    //B4: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B5: Lay node dau hang doi
        Node *node = dequeue(queue);
        //B5.1: Kiem tra node co gia tri bang voi gia tri can xoa
        if (node->data == data) {
            target = node;
        }
        //B6: Kiem tra con ben trai
        if (node->left != NULL) {
            //B6.1: Neu co thi dua vao hang doi
            enqueue(queue, node->left);
            //B6.2: Cap nhat lastParent thanh node duoc lay
            lastParent = node;
            //B6.3: Cap nhat lastNode thanh con ben trai
            lastNode = node->left;
        }
        //B7: Kiem tra con ben phai
        if (node->right != NULL) {
            //B7.1: Neu co thi dua vao hang doi
            enqueue(queue, node->right);
            //B7.2: Cap nhat lastParent thanh node duoc lay
            lastParent = node;
            //B7.3: Cap nhat lastNode thanh con ben phai
            lastNode = node->right;
        }
    }
    //B8: Neu khong tim thay  ket thuc ham
    if (target == NULL) {
        free(queue->arr);
        free(queue);
        return root;
    }
    //B9: Xu ly truong hop cay chi co 1 node va xoa node goc
    if (lastNode == NULL) {
        free(root);
        root = NULL;
    }else {
        //B10: Xoa node cuoi cung
        //B10.1: Gan du lieu lastNode vao target
        target->data = lastNode->data;
        //B10.2: Cap nhat con tro cua last parent
        if (lastNode == lastParent->left) {
            lastParent->left = NULL;
        }else {
            lastParent->right = NULL;
        }
        //B10.3: Giai phong lastNode
        free(lastNode);
    }
    //B11: Giai phong cac vung nho can thiet va tra ve root
    free(queue->arr);
    free(queue);
    return root;
}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
