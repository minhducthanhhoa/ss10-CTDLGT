#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;              
    struct Node* prev;    
    struct Node* next;     
} Node;

Node* initList() {
    return NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addFirst(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head != NULL) {
        newNode->next = *head; 
        (*head)->prev = newNode;
    }
    *head = newNode; 
}

void addLast(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; 
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; 
        newNode->prev = temp;
    }
}

void deleteFirst(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next; 
    if (*head != NULL) {
        (*head)->prev = NULL; 
    }
    free(temp); 
}

void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL; 
    } else {
        *head = NULL; 
    }
    free(temp);
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL || position <= 0) {
        printf("Vi tri khong hop le hoac danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Vi tri vuot qua danh sach!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next; 
    } else {
        *head = temp->next; 
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev; 
    }

    free(temp); 
}

void displayForward(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    printf("Danh sach tu dau den cuoi: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    printf("Danh sach tu cuoi ve dau: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* list = initList();
    int choice, value, position;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them node vao dau danh sach\n");
        printf("2. Them node vao cuoi danh sach\n");
        printf("3. Xoa node o dau danh sach\n");
        printf("4. Xoa node o cuoi danh sach\n");
        printf("5. Xoa node o vi tri bat ky\n");
        printf("6. Duyet danh sach tu dau den cuoi\n");
        printf("7. Duyet danh sach tu cuoi ve dau\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them vao dau: ");
                scanf("%d", &value);
                addFirst(&list, value);
                break;
            case 2:
                printf("Nhap gia tri can them vao cuoi: ");
                scanf("%d", &value);
                addLast(&list, value);
                break;
            case 3:
                deleteFirst(&list);
                printf("Da xoa node dau danh sach.\n");
                break;
            case 4:
                deleteLast(&list);
                printf("Da xoa node cuoi danh sach.\n");
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                deleteAtPosition(&list, position);
                break;
            case 6:
                displayForward(list);
                break;
            case 7:
                displayBackward(list);
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                freeList(&list);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 0);

    return 0;
}

