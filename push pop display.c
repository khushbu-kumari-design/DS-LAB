#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("Inserted: %d\n", x);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = stack[top--];
    printf("Deleted: %d\n", val);
    return val;
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 4);

    return 0;
}