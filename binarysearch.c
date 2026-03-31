#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, result;
    int a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(a, n, key);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}