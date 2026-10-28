#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insertion
struct Node* insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else {
        printf("Duplicate element not allowed\n");
    }

    return root;
}

// Searching
void search(struct Node *root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }

    if (root->data == key) {
        printf("Element found\n");
    }
    else if (key < root->data) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

// Preorder Traversal: Root, Left, Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Display BST using Inorder Traversal
// Inorder: Left, Root, Right
void display(struct Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, data, key;

    do {
        printf("\n\n--- BST MENU ---");
        printf("\n1. Insertion");
        printf("\n2. Searching");
        printf("\n3. Preorder Traversal");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);

                root = insert(root, data);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &key);

                search(root, key);
                break;

            case 3:
                printf("Preorder Traversal: ");

                if (root == NULL)
                    printf("Tree is empty");
                else
                    preorder(root);

                printf("\n");
                break;

            case 4:
                printf("BST elements: ");

                if (root == NULL)
                    printf("Tree is empty");
                else
                    display(root);

                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}