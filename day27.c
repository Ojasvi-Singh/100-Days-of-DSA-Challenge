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

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = createList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = createList(m);

    findIntersection(list1, list2);

    freeList(list1);
    freeList(list2);

    return 0;
}
