#include <stdio.h>

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert(int a[], int n, int ele, int pos) {
    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = ele;

    display(a, n + 1);
}

int main() {
    int a[50], n, ele, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &ele);

    printf("Enter position (0-based index): ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 0;
    }

    insert(a, n, ele, pos);

    return 0;
}