#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    struct Node* stack = NULL;
    char input[100];

    while (scanf("%s", input) != EOF) {
        if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))) {
            push(&stack, atoi(input));
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            
            switch (input[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }

    printf("%d\n", pop(&stack));
    return 0;
}
