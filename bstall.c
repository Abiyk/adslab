
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->data = key;
    node->left = node->right = NULL;

    return node;
}

// Insert a node
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        printf("%d already exists.\n", key);

    return root;
}

// Find minimum node
struct Node* minNode(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}



// Search for a node
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}



// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node has no left child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Node has no right child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        struct Node* succ = minNode(root->right);

        root->data = succ->data;

        root->right = deleteNode(root->right, succ->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder\n");
        printf("4. Preorder\n");
        printf("5. Postorder\n");
printf("6. Search\n");
printf("7. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                if (root == NULL)
                    printf("Tree is empty.\n");
                else {
                    struct Node* temp = root;
                    while (temp != NULL && temp->data != value) {
                        if (value < temp->data)
                            temp = temp->left;
                        else
                            temp = temp->right;
                    }

                    if (temp == NULL)
                        printf("%d not found.\n", value);
                    else {
                        root = deleteNode(root, value);
                        printf("%d deleted successfully.\n", value);
                    }
                }
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6: {
    printf("Enter value to search: ");
    scanf("%d", &value);

    struct Node* result = search(root, value);

    if (result == NULL)
        printf("%d not found in the tree.\n", value);
    else
        printf("%d found in the tree.\n", value);

    break;
}

case 7:
    return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
