#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* deleteKey(struct Node* head, int key) {
    if (head == NULL) return NULL;

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head;

    prev->next = temp->next;
    free(temp);

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, key;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* head = createList(n);

    if (scanf("%d", &key) != 1) {
        printList(head);
        freeList(head);
        return 0;
    }

    head = deleteKey(head, key);

    printList(head);
    freeList(head);

    return 0;
}
