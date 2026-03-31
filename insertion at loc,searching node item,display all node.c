#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, pos, key;

    while (1) {
        printf("\n1. Insert at position\n2. Search node\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, value, pos);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                pos = searchNode(head, key);
                if (pos != -1)
                    printf("Element found at position: %d\n", pos);
                else
                    printf("Element not found\n");
                break;

            case 3:
                display(head);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}