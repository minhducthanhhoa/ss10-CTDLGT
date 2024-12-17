#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int adjMatrix[MAX][MAX]; 
    int numVertices;         
} Graph;

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0; 
        }
    }
}

void addEdge(Graph* g, int src, int dest, int isDirected) {
    if (src >= g->numVertices || dest >= g->numVertices) {
        printf("Dinh khong ton tai!\n");
        return;
    }
    g->adjMatrix[src][dest] = 1; 
    if (!isDirected) {
        g->adjMatrix[dest][src] = 1; 
    }
}

void printAdjMatrix(Graph* g) {
    printf("\nMa tran ke cua do thi:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited); 
        }
    }
}

void performDFS(Graph* g, int startVertex) {
    bool visited[MAX] = {false};
    printf("Duyet DFS tu dinh %d: ", startVertex);
    DFS(g, startVertex, visited);
    printf("\n");
}

void BFS(Graph* g, int startVertex) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Duyet BFS tu dinh %d: ", startVertex);
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int vertices, choice, src, dest, startVertex, isDirected;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Do thi co huong hay khong? (1: Co huong, 0: Khong huong): ");
    scanf("%d", &isDirected);

    do {
        printf("\n--- MENU DO THI ---\n");
        printf("1. Them canh\n");
        printf("2. Hien thi ma tran ke\n");
        printf("3. Duyet DFS\n");
        printf("4. Duyet BFS\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh nguon va dinh dich (src dest): ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest, isDirected);
                break;
            case 2:
                printAdjMatrix(&g);
                break;
            case 3:
                printf("Nhap dinh bat dau DFS: ");
                scanf("%d", &startVertex);
                performDFS(&g, startVertex);
                break;
            case 4:
                printf("Nhap dinh bat dau BFS: ");
                scanf("%d", &startVertex);
                BFS(&g, startVertex);
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

