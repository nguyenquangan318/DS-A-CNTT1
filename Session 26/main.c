#include <stdio.h>
#include <stdlib.h>
//B1: Xay dung cau truc can thiet (yeu cau, hang doi)
typedef struct Request {
    int id;
    char issue[50];
    int priority;
} Request;
typedef struct Queue {
    Request *requests;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->requests = (Request *) malloc(sizeof(Request) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, Request request) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->requests[queue->rear] = request;
}
Request createRequest() {
    Request request;
    printf("Enter request id: ");
    scanf("%d", &request.id);
    printf("Enter request: ");
    fflush(stdin);
    gets(request.issue);
    printf("Enter request priority: ");
    scanf("%d", &request.priority);
    return request;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    queue->front++;
}
void showTopRequest(Queue *queue) {
    Request topRequest = queue->requests[queue->front];
    printf("Request id: %d\n", topRequest.id);
    printf("Request: %s\n", topRequest.issue);
    printf("Priority: %d\n", topRequest.priority);
}
void displayQueue(Queue *queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        Request request = queue->requests[i];
        printf("Request id: %d\n", request.id);
        printf("Request: %s\n", request.issue);
        printf("Priority: %d\n", request.priority);
    }
}
int main(void) {
    int choice;
    Queue *highQueue = createQueue(50);
    Queue *lowQueue = createQueue(50);
    do {
        printf("1. REQUEST\n");
        printf("2. HANDLE REQUEST\n");
        printf("3. TOP REQUEST\n");
        printf("4. ALL REQUEST\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //Tao ra yeu cau
                Request request = createRequest();
                //Them yeu cau vao hang doi tuong ung
                if (request.priority == 1) {
                    enqueue(highQueue, request);
                }else {
                    enqueue(lowQueue, request);
                }
                break;
            case 2:
                //Kiem tra hang doi co do uu tien cao
                if (!isEmpty(highQueue)) {
                    //Neu hang doi khong trong thi xu ly yeu cau
                    dequeue(highQueue);
                }else {
                    //Neu hang doi trong thi kiem tra hang doi co do uu tien thap
                    if (!isEmpty(lowQueue)) {
                        //Neu hang doi khong trong thi xu ly yeu cau
                        dequeue(lowQueue);
                    }else {
                        //Neu hang doi trong thi thong bao
                        printf("No request in queue");
                    }
                }
                break;
            case 3:
                //Kiem tra hang doi co do uu tien cao
                if (!isEmpty(highQueue)) {
                    //Neu hang doi khong trong thi in yeu cau
                    showTopRequest(highQueue);
                }else {
                    //Neu hang doi trong thi kiem tra hang doi co do uu tien thap
                    if (!isEmpty(lowQueue)) {
                        //Neu hang doi khong trong thi in yeu cau
                        showTopRequest(lowQueue);
                    }else {
                        //Neu hang doi trong thi thong bao
                        printf("No request in queue");
                    }
                }
                break;
            case 4:
                //In hang doi co do uu tien cao
                if (!isEmpty(highQueue)) {
                    displayQueue(highQueue);
                }
                //In hang doi co do uu tien thap
                if (!isEmpty(lowQueue)) {
                    displayQueue(lowQueue);
                }
                //In neu ca 2 hang doi trong
                if (isEmpty(highQueue) && isEmpty(lowQueue)) {
                    printf("No request in queue");
                }
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 5);
    free(highQueue);
    free(lowQueue);
    return 0;
}