#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
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
    int choice, value;

    while (1) {
        printf("\n1. Insert at beginning\n2. Delete first node\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 2:
                head = deleteFirstNode(head);
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