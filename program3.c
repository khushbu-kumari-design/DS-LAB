#include <stdio.h>

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int del(int a[], int n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    display(a, n - 1);

    return n - 1;
}

int main() {
    int a[50], n, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return 0;
    }

    n = del(a, n, pos);

    return 0;
}