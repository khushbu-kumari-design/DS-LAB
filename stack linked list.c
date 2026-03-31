#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}

void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                display(top);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}