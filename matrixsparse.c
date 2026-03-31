#include <stdio.h>

void checkSparse(int a[4][4]) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) {
                count++;
            }
        }
    }

    if (count > (4 * 4) / 2) {
        int b[16][3];
        int k = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] != 0) {
                    b[k][0] = i;
                    b[k][1] = j;
                    b[k][2] = a[i][j];
                    k++;
                }
            }
        }

        printf("Sparse matrix\n");
        printf("Row Col Value\n");
        for (int i = 0; i < k; i++) {
            printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
        }
    } else {
        printf("Not a sparse matrix\n");
    }
}

int main() {
    int a[4][4];

    printf("Enter elements of 4x4 matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    checkSparse(a);

    return 0;
}