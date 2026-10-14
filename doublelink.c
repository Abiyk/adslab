#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin() {
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &n->data);

    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

void insert_end() {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct node *t = head;

    if (n == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &n->data);

    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
}

void display() {
    struct node *t = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: ");

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("\n");
}

void delete_node() {
    struct node *t = head;
    int x;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &x);

    while (t != NULL && t->data != x)
        t = t->next;

    if (t == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);

    printf("Node deleted successfully!\n");
}

void reverse() {
    struct node *t = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (t->next != NULL)
        t = t->next;

    printf("Reverse: ");

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->prev;
    }

    printf("\n");
}

int main() {
    int ch;

    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Display Forward\n");
        printf("4. Delete Node\n");
        printf("5. Display Reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                display();
                break;

            case 4:
                delete_node();
                break;

            case 5:
                reverse();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}