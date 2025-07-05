#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc cua mot phan tu trong singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Xay dung ham khoi tao phan tu
Node* createNode(int data) {
    //B1: Khoi tao node moi
    Node* node = (Node*)malloc(sizeof(Node));
    //B2: Gan gia tri cho node moi
    node->data = data;
    //B3: Gan con tro next cho node moi
    node->next = NULL;
    //B4: Tra ve gia tri
    return node;
}

//Xay dung ham hien thi danh sach lien ket don
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Xay dung ham them vao cuoi
Node* insertAtEnd(Node* head) {
    //B1: Khoi tao phan tu can duoc them moi
    Node* newNode = createNode(4);
    //Neu danh sach trong thi truc tiep thay doi head va ket thuc
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //B2: Duyet den phan tu cuoi cung
    Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    //B3: Tien hanh cap nhat cac con tro can thiet
    lastNode->next = newNode;
    //B4: Tra ve danh sach lien ket don moi
    return head;
}

//Xay dung ham xoa o cuoi
Node* deleteAtEnd(Node* head) {
    //Neu khong co phan tu nao trong danh sach lien ket don
    if (head == NULL) {
        return head;
    }
    //Truong hop danh sach chi co 1 phan tu
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    //Truong hop co nhieu hon 1 phan tu
    //Duyet den phan tu gan cuoi cung
    Node* secondLastNode = head;
    while (secondLastNode->next->next != NULL) {
        secondLastNode = secondLastNode->next;
    }
    //Giai phong phan tu cuoi cung
    free(secondLastNode->next);
    //Cap nhat cac con tro can thiet
    secondLastNode->next = NULL;
    //Tra ve danh sach moi
    return head;
}

int main(void) {
    //Khoi tao danh sach lien ket don
    Node* head = NULL;
    //Khoi tao 3 node co gia tri la 1, 2, 3
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    //Dua 3 node vao danh sach lien ket don theo dung thu tu
    head = node1;
    node1->next = node2;
    node2->next = node3;
    // head->1->2->3->NULL
    displayList(head);
    head = insertAtEnd(head);
    displayList(head);
    head = deleteAtEnd(head);
    head = deleteAtEnd(head);
    displayList(head);
    return 0;
}