#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;             
    struct Node* next;    
} Node;

typedef struct Queue {
    Node* front;          
    Node* rear;           
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;  
    } else {
        q->rear->next = newNode;       
        q->rear = newNode;             
    }
    printf("Da them %d vao hang doi.\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong the xoa.\n");
        return -1;  
    }
    Node* temp = q->front;        
    int value = temp->data;       
    q->front = q->front->next;   

    if (q->front == NULL) {       
        q->rear = NULL;
    }
    free(temp);                   
    printf("Da xoa %d khoi hang doi.\n", value);
    return value;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong! Khong co phan tu dau.\n");
        return -1; 
    }
    return q->front->data;  
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int main() {
    Queue queue;  
    initQueue(&queue);

    int choice, value;

    do {
        printf("\n--- MENU HANG DOI ---\n");
        printf("1. Them phan tu vao hang doi (Enqueue)\n");
        printf("2. Xoa phan tu khoi hang doi (Dequeue)\n");
        printf("3. Xem phan tu dau hang doi (Peek)\n");
        printf("4. Kiem tra hang doi rong\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                value = peek(&queue);
                if (value != -1) {
                    printf("Phan tu dau hang doi: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&queue)) {
                    printf("Hang doi dang rong.\n");
                } else {
                    printf("Hang doi khong rong.\n");
                }
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                freeQueue(&queue);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 0);

    return 0;
}

