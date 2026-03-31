#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void insert(int x) {
    if (rear == MAX) {
        printf("Queue Overflow!\n");
        return;
    }
    queue[rear++] = x;
    printf("Inserted: %d\n", x);
}

int delete() {
    if (front == rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = queue[front++];
    printf("Deleted: %d\n", val);
    return val;
}

void traverse() {
    if (front == rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                delete();
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}