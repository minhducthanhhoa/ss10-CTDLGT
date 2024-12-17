#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;            
    struct Node* next;   
} Node;

Node* initList() {
    return NULL;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addFirst(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
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
    }
}

void deleteFirst(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

Node* search(Node* head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
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
    int choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3. Xoa phan tu dau danh sach\n");
        printf("4. Xoa phan tu cuoi danh sach\n");
        printf("5. Tim kiem phan tu\n");
        printf("6. Hien thi danh sach\n");
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
                printf("Da xoa phan tu dau danh sach.\n");
                break;
            case 4:
                deleteLast(&list);
                printf("Da xoa phan tu cuoi danh sach.\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (search(list, value)) {
                    printf("Tim thay gia tri %d trong danh sach.\n", value);
                } else {
                    printf("Khong tim thay gia tri %d trong danh sach.\n", value);
                }
                break;
            case 6:
                printf("Danh sach hien tai: ");
                displayList(list);
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

