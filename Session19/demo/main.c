#include <stdio.h>
#include <stdlib.h>

//B1: Xay dung cau truc cua 1 node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
//B2: Xay dung ham khoi tao node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//B3: Xay dung ham duyet preorder
void preorderDFS(Node *root) {
    //Dieu kien dung
    if (root == NULL) {
        return;
    }
    //In ra node duoc xet
    printf("%d ", root->data);
    //Thuc hien bai toan voi cay con ben trai
    preorderDFS(root->left);
    //Thuc hien bai toan voi cay con ben phai
    preorderDFS(root->right);
}
void inorderDFS(Node *root) {
    //Xay dung dieu kien dung
    if (root == NULL) {
        return;
    }
    //Thuc hien bai toan voi cay con ben trai
    inorderDFS(root->left);
    //In ra node duoc xet
    printf("%d ", root->data);
    //Thuc hien bai toan voi cay con ben phai
    inorderDFS(root->right);
}
void postorderDFS(Node *root) {
    //Xay dung dieu kien dung
    if (root == NULL) {
        return;
    }
    //Thuc hien bai toan voi cay con ben trai
    postorderDFS(root->left);
    //Thuc hien bai toan voi cay con ben phai
    postorderDFS(root->right);
    //In ra node duoc xet
    printf("%d ", root->data);
}

//B2: Xay dung hang doi va cac phuong thuc can thiet
//Xay dung cau truc hang doi
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
//Xay dung ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->arr = (Node **)malloc(sizeof(Node *) * capacity);
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
void levelorderBFS(Node *root) {
    //B1: Kiem tra cay khong co node nao
    if (root == NULL) {
        return;
    }
    //B3: Khoi tao hang doi
    Queue *queue = createQueue(100);
    //B4: Dua node goc vao hang doi
    enqueue(queue, root);
    //B5: Trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //B6: Lay node dau hang doi va in ra
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        //B7: Kiem tra va day cac node con cua node duoc in vao hang doi
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
}

int main(void) {
    Node *root = NULL;
    root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    printf("Preorder DFS: \n");
    preorderDFS(root);
    printf("\n");
    printf("Inorder DFS: \n");
    inorderDFS(root);
    printf("\n");
    printf("Postorder DFS: \n");
    postorderDFS(root);
    printf("\n");
    printf("Level order BFS: \n");
    levelorderBFS(root);
    return 0;
}