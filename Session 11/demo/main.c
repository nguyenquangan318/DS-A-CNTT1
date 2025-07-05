#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc du lieu cua 1 node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

//Ham khoi tao node moi
Node *createNode(int data) {
    //B1: Cap phat bo nho cho node moi
    Node *newNode = (Node *)malloc(sizeof(Node));
    //B2: Gan gia tri du lieu cho node moi
    newNode->data = data;
    //B3: Dat cac con tro cho node moi
    newNode->next = NULL;
    newNode->prev = NULL;
    //B4: Tra ve dia chi cua node moi
    return newNode;
}

//Ham duyet va in toan bo danh sach
void displayList(Node *head) {
    //B1: duyet qua tung node cho den khi gap NULL
    Node *current = head;
    printf("NULL<-");
    while (current != NULL) {
        //B2: In ra du lieu cua node
        printf("%d", current->data);
        if (current->next == NULL) {
            printf("->");
        }else {
            printf("<-->");
        }
        //B3: Dich den node tiep theo
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

//Ham them vao cuoi danh sach
Node *insertAtEnd(Node *head, int data) {
    //B1: Khoi tao node moi
    Node *newNode = createNode(data);
    //B2: Xu ly voi danh sach trong
    if (head == NULL) {
        //B2.1: Gan truc tiep head thanh node moi
        head = newNode;
    }else {
        //B3: Duyet den node cuoi cung
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        //B4: Cap nhat cac con tro can thiet de them
        current->next = newNode;
        newNode->prev = current;
    }
    //B5: Tra ve con tro head moi
    return head;
}

//Ham them vao dau danh sach
Node *insertAtStart(Node *head, int data) {
    Node *newNode = createNode(data);
    //B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        head = newNode;
    }else {
        //B2: Cap nhat cac con tro can thiet de them
        newNode->next = head;
        head->prev = newNode;
        //B3: Gan lai head moi
        head = newNode;
    }
    //B4: Tra ve head moi
    return head;
}

//Ham xoa o cuoi danh sach
Node *deletAtEnd(Node *head) {
    //B1: Xu ly truong hop danh sach trong
    if (head == NULL) {
        return head;
    }
    //B2: Xu lu truong hop danh sach chi co 1 node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    //B3: Duyet den node cuoi danh sach
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    //B4: Cap nhat lai cac con tro de xoa
    current->prev->next = NULL;
    //B5: Giai phong node cuoi cung
    free(current);
    //B6: Tra ve head moi
    return head;
}

int main(void) {
    //Tao ra 3 phan tu va dua vao danh sach lien ket doi
    Node *head = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    head->next = node1;
    node1->prev = head;
    node1->next = node2;
    node2->prev = node1;
    displayList(head);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    displayList(head);
    head = deletAtEnd(head);
    head = deletAtEnd(head);
    head = deletAtEnd(head);
    displayList(head);
    return 0;
}