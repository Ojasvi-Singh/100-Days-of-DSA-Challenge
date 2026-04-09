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

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || n <= 1) return head;

    k = k % n;
    if (k == 0) return head;

    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head;

    int stepsToNewHead = n - k;
    struct Node* newTail = tail;
    for (int i = 0; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, k;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* head = createList(n);

    if (scanf("%d", &k) != 1) {
        printList(head);
        freeList(head);
        return 0;
    }

    head = rotateRight(head, k, n);

    printList(head);
    freeList(head);

    return 0;
}
