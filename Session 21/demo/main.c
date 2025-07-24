#include <stdio.h>
#include <stdlib.h>

//Xay dung cau truc do thi
typedef struct Graph {
    int V;
    int **adjMatrix;
} Graph;

//Xay dung ham khoi tao do thi
Graph *createGraph(int V) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    //Cap phat bo nho cho mang 2 chieu
    graph->adjMatrix = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        //cap phat bo nho cho tung mang con ben trong mang 2 chieu
        graph->adjMatrix[i] = (int *) calloc(V, sizeof(int));
    }
    return graph;
}

//Xay dung ham thiet lap canh
void addEdge(Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; //Neu la do thi vo huong
}

//Xay dung ham in do thi
void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

//In do thi
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}


//duyet do thi DFS
void DFSUtil(Graph *graph, int src, int *visited) {
    //B1: Danh dau src la da duoc duyet qua
    visited[src] = 1;
    //B2: In dinh src ra
    printf("%d ", src);
    //B3: Su dung vong lap de kiem tra tat ca duong di tu dinh src
    for (int i = 0; i < graph->V; i++) {
        //B4: Kiem tra co duong den dinh tiep theo
        // va dinh do chua tung duoc duyet
        if (graph->adjMatrix[src][i] == 1 && visited[i] == 0) {
            //B5: Goi lai ham voi dinh tiep theo duoc duyet
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int src) {
    //B1: Khoi tao mang visited
    int *visited = (int *) calloc(graph->V, sizeof(int));
    //B2: In ra thong bao
    printf("DFS tu dinh %d: ", src);
    //B3: Goi ham
    DFSUtil(graph, src, visited);
    //B4: Giai phong mang visited
    free(visited);
}

//Duyet do thi BFS
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->arr = (int *) malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = value;
}
int isQueueEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front++];
}

void BFS(Graph *graph, int src) {
    //B1: Khoi tao mang visited
    int *visited = (int *) calloc(graph->V, sizeof(int));
    //B2: Danh dau dinh src da duoc duyet
    visited[src] = 1;
    //B3: Dua dinh src vao hang doi
    Queue *queue = createQueue(graph->V);
    enqueue(queue, src);
    //B4: Trien khai vong lap den khi hang doi trong
    while (!isQueueEmpty(queue)) {
        //B5: Lay dinh tu dau hang doi va in ra
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);
        //B6: Kiem tra toan bo duong di tu dinh duoc lay ra
        for (int i = 0; i < graph->V; i++) {
            //B7: Neu co duong di va dinh chua duoc duyet
            if (graph->adjMatrix[currentNode][i] == 1 && visited[i] == 0) {
                //B8: day dinh vao hang doi
                enqueue(queue, i);
                //B9: danh dau dinh da duoc duyet
                visited[i] = 1;
            }
        }
    }
    free(visited);
    free(queue->arr);
    free(queue);
}


int main(void) {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    printMatrix(graph);
    printGraph(graph);
    DFS(graph, 0);
    return 0;
}
