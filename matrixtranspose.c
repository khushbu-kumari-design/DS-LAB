#include <stdio.h>

void transpose(int a[10][10], int n) {
    int t[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("Transpose of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], n;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    transpose(a, n);

    return 0;
}