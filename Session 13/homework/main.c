#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc cho mot node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

//Xay dung ham khoi tao node
Node *createNode(int data) {
    //B1: Cap phat bo nho cho node moi
    Node *newNode = (Node *) malloc(sizeof(Node));
    //B2: Gan gia tri
    newNode->data = data;
    //B3: Gan cac con tro
    newNode->next = NULL;
    newNode->prev = NULL;
    //B4: Tra ve dia chi cua node moi
    return newNode;
}

//Xay dung ham duyet toan bo danh sach
void displayList(Node *head) {
    Node *current = head;
    printf("NULL<-");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next == NULL) {
            printf("->");
        } else {
            printf("<-->");
        }
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

//Xay dung ham them node vao vi tri
Node *insertAtPos(Node *head, int data, int pos) {
    //B1: Tao ra node moi
    Node *newNode = createNode(data);
    //B2: Xu ly truong hop them vao dau
    if (pos == 0) {
        //B2.1: Cap nhat con tro next cua new node
        newNode->next = head;
        //B2.2: Cap nhat con tro prev cua head neu danh sach khong trong
        if (head != NULL) {
            head->prev = newNode;
        }
        //B2.3: Gan lai va tra ve head moi
        head = newNode;
        return head;
    }
    //B3: Duyet den node nam o truoc vi tri can them hoac duyet den cuoi danh sach
    Node *current = head;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    //B4: Neu duyet den cuoi danh sach ket thuc
    if (current == NULL) {
        free(newNode);
        return head;
    }
    //B5: Cap nhat cac con tro can thiet de them moi
    newNode->prev = current;
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    //B6: Tra ve head moi
    return head;
}

//Xay dung ham xoa node tai vi tri
Node *deleteAtPos(Node *head, int pos) {
    //B1: Xu ly truong hop pos < 0
    if (pos < 0) {
        return head;
    }
    //B2: Xu ly truong hop danh sach trong
    if (head == NULL) {
        return head;
    }
    //B3: Duyet den node nam o vi tri can xoa hoac duyet den het danh sach
    Node *current = head;
    for (int i = 0; i < pos && current != NULL; i++) {
        current = current->next;
    }
    //B4: Xu ly truong hop duyet het danh sach
    if (current == NULL) {
        return head;
    }
    //B5: Cap nhat cac con tro can thiet de xoa
    //B5.1: Xu ly truong hop xoa node o dau
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    //B5.2: Xu ly trong hop xoa node o cuoi
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    //B5.3: Gan lai head neu xoa o dau
    if (head == current) {
        head = current->next;
    }
    free(current);
    //B6: Tra ve head moi
    return head;
}

int main(void) {
    return 0;
}
