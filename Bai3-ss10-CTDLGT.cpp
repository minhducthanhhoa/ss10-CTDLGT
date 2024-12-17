#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;             
    struct Node* next;    
} Node;

typedef struct Stack {
    Node* top;            
} Stack;

void initStack(Stack* s) {
    s->top = NULL;  
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;      
    newNode->next = s->top;     
    s->top = newNode;           
    printf("Da them %d vao ngan xep.\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong! Khong the xoa.\n");
        return -1; 
    }
    Node* temp = s->top;      
    int value = temp->data;   
    s->top = temp->next;      
    free(temp);               
    printf("Da xoa %d khoi ngan xep.\n", value);
    return value;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong! Khong co phan tu tren cung.\n");
        return -1; 
    }
    return s->top->data;  
}

void freeStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

int main() {
    Stack stack; 
    initStack(&stack);

    int choice, value;

    do {
        printf("\n--- MENU NGAN XEP ---\n");
        printf("1. Them phan tu vao ngan xep (Push)\n");
        printf("2. Xoa phan tu khoi ngan xep (Pop)\n");
        printf("3. Xem phan tu tren cung (Peek)\n");
        printf("4. Kiem tra ngan xep rong\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Phan tu tren cung cua ngan xep: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Ngan xep dang rong.\n");
                } else {
                    printf("Ngan xep khong rong.\n");
                }
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                freeStack(&stack);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 0);

    return 0;
}

