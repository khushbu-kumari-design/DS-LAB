#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int pno;
    char name[50];
    float cost;
};

void display(struct Product p[], int n) {
    printf("\nProducts with cost between 100 and 1000:\n");

    for (int i = 0; i < n; i++) {
        if (p[i].cost >= 100 && p[i].cost <= 1000) {
            printf("Product No: %d\n", p[i].pno);
            printf("Name: %s\n", p[i].name);
            printf("Cost: %.2f\n\n", p[i].cost);
        }
    }
}

int main() {
    struct Product *p;
    int n;

    printf("Enter number of products: ");
    scanf("%d", &n);

    p = (struct Product*)malloc(n * sizeof(struct Product));

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    printf("\nEnter product details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nProduct %d:\n", i + 1);

        printf("Enter product number: ");
        scanf("%d", &p[i].pno);

        getchar();

        printf("Enter product name: ");
        fgets(p[i].name, 50, stdin);
        p[i].name[strcspn(p[i].name, "\n")] = '\0';

        printf("Enter cost: ");
        scanf("%f", &p[i].cost);
    }

    display(p, n);

    free(p);

    return 0;
}