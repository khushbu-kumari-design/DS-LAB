#include <stdio.h>

#define MAX 5

int cq[MAX], front = -1, rear = -1;

void insert(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = x;
    printf("Inserted: %d\n", x);
}

int delete() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int val = cq[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("Deleted: %d\n", val);
    return val;
}

void traverse() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Circular Queue elements:\n");
    int i = front;

    while (1) {
        printf("%d ", cq[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
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