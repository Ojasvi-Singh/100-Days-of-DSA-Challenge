#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        for (int i = 0; i < n; i++) {
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }

    return 0;
}
