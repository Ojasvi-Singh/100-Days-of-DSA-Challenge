#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        return;
    }
    top--;
}

void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    if (scanf("%d", &m) != 1) {
        display();
        return 0;
    }

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}
