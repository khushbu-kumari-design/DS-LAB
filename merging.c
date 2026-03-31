#include <stdio.h>

void mergeArrays(int A[], int B[], int C[], int n1, int n2) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < n1)
        C[k++] = A[i++];

    while (j < n2)
        C[k++] = B[j++];
}

int main() {
    int A[5], B[5], C[10];

    printf("Enter 5 elements of array A in ascending order:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &A[i]);

    printf("Enter 5 elements of array B in ascending order:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &B[i]);

    mergeArrays(A, B, C, 5, 5);

    printf("Merged sorted array C:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", C[i]);
    printf("\n");

    return 0;
}