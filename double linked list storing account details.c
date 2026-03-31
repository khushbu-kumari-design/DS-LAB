#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
    struct Account *prev, *next;
};

struct Account* createList(int n) {
    struct Account *head = NULL, *temp, *newNode;

    for (int i = 1; i <= n; i++) {
        newNode = (struct Account*)malloc(sizeof(struct Account));

        printf("\nEnter details of Account %d\n", i);
        printf("Account Number: ");
        scanf("%d", &newNode->accNo);
        printf("Name: ");
        scanf(" %[^\n]", newNode->name);
        printf("Balance: ");
        scanf("%f", &newNode->balance);

        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Account* head) {
    struct Account* temp = head;

    printf("\n--- Account Details ---\n");
    while (temp != NULL) {
        printf("\nAcc No: %d", temp->accNo);
        printf("\nName: %s", temp->name);
        printf("\nBalance: %.2f\n", temp->balance);
        temp = temp->next;
    }
}

float totalBalance(struct Account* head) {
    struct Account* temp = head;
    float total = 0;

    while (temp != NULL) {
        total += temp->balance;
        temp = temp->next;
    }
    return total;
}

int main() {
    int n;
    struct Account* head;
    float total;

    printf("Enter number of account holders: ");
    scanf("%d", &n);

    head = createList(n);

    display(head);

    total = totalBalance(head);

    printf("\nTotal Balance of all account holders = %.2f\n", total);

    return 0;
}