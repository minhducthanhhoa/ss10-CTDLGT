#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;             
    struct Node* left;    
    struct Node* right;   
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {  
        return createNode(value);
    }
    if (value < root->data) {  
        root->left = insert(root->left, value);
    } else if (value > root->data) {  
        root->right = insert(root->right, value);
    } else {
        printf("Phan tu %d da ton tai trong cay.\n", value);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        preOrder(root->left);      
        preOrder(root->right);     
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);       
        printf("%d ", root->data); 
        inOrder(root->right);      
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);     
        postOrder(root->right);    
        printf("%d ", root->data); 
    }
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {  
        return root;
    }
    if (value < root->data) {  
        return search(root->left, value);
    } else {                  
        return search(root->right, value);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL; 
    int choice, value;

    do {
        printf("\n--- MENU CAY NHI PHAN ---\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Duyet cay theo thu tu truoc (PreOrder)\n");
        printf("3. Duyet cay theo thu tu giua (InOrder)\n");
        printf("4. Duyet cay theo thu tu sau (PostOrder)\n");
        printf("5. Tim kiem phan tu trong cay\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Duyet theo PreOrder: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet theo InOrder: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet theo PostOrder: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Phan tu %d co ton tai trong cay.\n", value);
                } else {
                    printf("Phan tu %d khong ton tai trong cay.\n", value);
                }
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                freeTree(root);
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 0);

    return 0;
}

