#include <stdio.h>

#define SIZE 10

int MAX(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}


int MIN(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main() {
    int a[SIZE];

    printf("Enter 10 numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &a[i]);
    }

    printf("Max: %d\n", MAX(a, SIZE));
    printf("Min: %d\n", MIN(a, SIZE));

    return 0;
}