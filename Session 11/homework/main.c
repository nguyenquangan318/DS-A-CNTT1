#include <stdio.h>
#include <stdlib.h>

//cau truc node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//Ham tao phan tu
Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Ham in danh sach
void displayList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Ham them phan tu vao vi tri bat ky
Node *insertAtPos(Node *head, int data, int pos) {
    //B1: Kiem tra vi tri can them < 0
    if (pos<0) {
        return head;
    }
    //B2: Kiem tra va xu ly truong hop them vao dau (pos == 0)
    if (pos == 0) {
        struct Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *curr = head;
    //B3: Xu ly truong hop pos > 0
    //B3.1: Duyet den phan tu nam o truoc vi tri can them hoac NULL
    for (int i=0; i<pos-1 && curr == NULL; i++) {
        curr = curr->next;
    }
    //Neu duyet het danh sach thi ket thuc
    if (curr == NULL) {
        return head;
    }
    //Cap nhat cac con tro can thiet de tien hanh them moi
    struct Node *newNode = createNode(data);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;

}

//Xoa o vi tri bat ky
Node *deleteAtPos(Node *head, int pos) {
    //B1: Kiem tra truong hop pos < 0
    if (pos < 0) {
        return head;
    }
    //B2: Kiem tra truong hop danh sach trong
    if (head == NULL) {
        return head;
    }
    //B3: Kiem tra truong hop them vao dau (pos == 0)
    Node *curr = head;
    if (pos == 0) {
        head = head->next;
        free(curr);
        return head;
    }
    //B4: Thuc hien them vao vi tri bat ky
    Node *prev = NULL;
    //B4.1: Duyet den phan tu o vi tri can xoa
    for (int i=0; i<pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    //B4.2: Neu duyet het danh sach
    if (curr == NULL) {
        return head;
    }
    //B4.3: Cap nhat cac con tro can thiet de tien hanh xoa
    prev->next = curr->next;
    free(curr);
    return head;

}

int main(void) {
    printf("Hello, World!\n");
    return 0;
}